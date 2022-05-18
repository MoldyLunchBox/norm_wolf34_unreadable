/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:51:01 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/18 14:26:53 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_obj(t_obj *obj, t_vars_obj vars_obj, SDL_Texture *texture)
{
	obj->x = vars_obj.x;
	obj->y = vars_obj.y;
	obj->frame_width = vars_obj.frame_width;
	obj->frame_higth = vars_obj.frame_higth;
	obj->state = vars_obj.state;
	obj->size_x = vars_obj.size_x;
	obj->size_y = vars_obj.size_y;
	obj->frame_num = vars_obj.frame_num;
	obj->surface_w = vars_obj.surface_w;
	obj->prev_state = vars_obj.prev_state;
	obj->texture = texture;
	obj->alive = SDL_TRUE;
	obj->fps = 2;
	obj->row = 0;
	obj->damage = 3;
	obj->dist_to_player = 15;
}

void	sprite_in_vision(t_player *player, t_obj *o_s, t_env *env, float dif)
{
	t_rec		rec;
	t_sp_vision	vars;

	o_s->h = ((WALL_H * 220) / o_s->dist_to_player) / o_s->size_y;
	o_s->w = ((WALL_H * 220) / o_s->dist_to_player) / o_s->size_x;
	vars.sx = range_conv_val((t_pnt){dtor(player->fov / 2),
			-dtor(player->fov / 2)}, (t_pnt){W_W, -o_s->w}, dif);
	vars.on_floor = ((WALL_H * 220) / o_s->dist_to_player) / 2;
	if (o_s->state == 5)
		vars.on_floor *= -1;
	if (o_s->state == 2)
		enemy_damage_die(player, o_s, env, (t_pnt){vars.sx, vars.on_floor});
	vars.j = (int)(vars.sx);
	while (vars.j < (int)(vars.sx + o_s->w) && vars.j < 800)
	{
		if (o_s->dist_to_player < player->dist[vars.j])
		{
			init_rect_sprite(o_s, &rec, &vars);
			SDL_RenderCopyEx(env->rend, o_s->texture,
				&rec.rect0, &rec.rect1, 0, NULL, SDL_FLIP_NONE);
		}
		vars.j++;
	}
}

void	sort_sprites(t_obj *ob_sprites, int num_sp)
{
	int		i;
	int		j;
	t_obj	temp;

	while (i < num_sp)
	{
		while (j < (num_sp - 1 - i))
		{
			if (ob_sprites[j].dist_to_player < ob_sprites[j + 1].dist_to_player)
			{
				temp = ob_sprites[j];
				ob_sprites[j] = ob_sprites[j + 1];
				ob_sprites[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sprites2(t_player *player, t_obj *ob_sprites, t_env *env, int i)
{
	enemy_movement(env, player, &ob_sprites[i]);
	enemy_collision(&ob_sprites[i], ob_sprites, env);
	enemy_animation(player, &ob_sprites[i], env);
	player_damage_lose(player, &ob_sprites[i], env);
}

void	update_sprites(t_player *player, t_obj *ob_sprites, t_env *env)
{
	int		i;
	float	dist;

	i = 0;
	while (i < env->num_sprites)
	{
		if (ob_sprites[i].state == 2)
			sprites2(player, ob_sprites, env, i);
		if (ob_sprites[i].state == 3)
			coin_collect(player, &ob_sprites[i], env);
		if (ob_sprites[i].state == 4)
			aid_kit_collect(player, &ob_sprites[i], env);
		i++;
	}
	i = 0;
	while (i < env->num_sprites)
	{
		dist = distance(player->x, player->y, ob_sprites[i].x, ob_sprites[i].y);
		ob_sprites[i].dist_to_player = dist;
		i++;
	}
	sort_sprites(ob_sprites, env->num_sprites);
}
