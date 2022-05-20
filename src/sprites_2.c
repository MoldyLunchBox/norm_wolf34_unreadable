/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:08:28 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/19 18:50:50 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	select_texture_2(t_texture *t, t_env *env)
{
	if (t->num == 9)
		(t->img) = env->walls[7];
	if (t->num == 10)
		(t->img) = env->walls[8];
	if (t->num == 11)
		(t->img) = env->walls[9];
	if (t->num == 12)
		(t->img) = env->walls[10];
	if (t->num == 13)
		(t->img) = env->walls[11];
	if (t->num == 14)
		(t->img) = env->walls[12];
	if (t->num == 15)
		(t->img) = env->walls[13];
	if (t->num == 16)
		(t->img) = env->quit[env->frame_quit];
	if (t->num == 17)
		(t->img) = env->beach[env->frame_beach];
}

void	select_texture(t_texture *t, t_env *env)
{
	if (t->num == 1)
		(t->img) = env->walls[0];
	if (t->num == 2)
		(t->img) = env->doors[env->frame_door];
	if (t->num == 3)
		(t->img) = env->walls[1];
	if (t->num == 4)
		(t->img) = env->walls[2];
	if (t->num == 5)
		(t->img) = env->walls[3];
	if (t->num == 6)
		(t->img) = env->walls[4];
	if (t->num == 7)
		(t->img) = env->walls[5];
	if (t->num == 8)
		(t->img) = env->walls[6];
	select_texture_2(t, env);
}

void	coin_collect(t_player *player, t_obj *ob_sprites, t_env *env)
{
	if (distance(player->x, player->y, ob_sprites->x, ob_sprites->y) < 15)
	{
		Mix_PlayChannel(1, env->coin_sound, 0);
		ob_sprites->state = 0;
		env->solde += 10;
	}
}

void	aid_kit_collect(t_player *player, t_obj *ob_sprites, t_env *env)
{
	if (distance(player->x, player->y, ob_sprites->x, ob_sprites->y) < 15)
	{
		Mix_PlayChannel(1, env->aid_kit_sound, 0);
		ob_sprites->state = 0;
		player->blood += 50;
		if (player->blood > W_W / 4)
			player->blood = W_W / 4;
		player->life = (SDL_Rect){40, W_H - 32, player->blood, 5};
	}
}
