/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:51:55 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/18 12:10:19 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_pnt(t_pnt *p, t_player *player)
{
	const uint8_t	*keys;

	keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_S])
	{
		p->ma -= cos(player->a);
		p->mi += sin(player->a);
	}
	if (keys[SDL_SCANCODE_W])
	{
		p->ma += cos(player->a);
		p->mi -= sin(player->a);
	}
	if (keys[SDL_SCANCODE_A])
	{
		p->ma += cos(player->a + PI / 2.0f);
		p->mi -= sin(player->a + PI / 2.0f);
	}
	if (keys[SDL_SCANCODE_D])
	{
		p->ma += cos(player->a - PI / 2.0f);
		p->mi -= sin(player->a - PI / 2.0f);
	}
}

t_pnt	movement(t_player *player)
{
	t_pnt			p;

	p.ma = 0;
	p.mi = 0;
	init_pnt(&p, player);
	return (p);
}

void	hit_sprites(t_player *player, t_obj *ob_sprites, t_env *env)
{
	int	s;

	s = 0;
	while (s < env->num_sprites)
	{
		if ((ob_sprites[s].state == 1 || ob_sprites[s].state
				== 2) && ob_sprites[s].dist_to_player < 11)
			player_sprite_cond(player, ob_sprites, s);
		if (ob_sprites[s].prev_state == 5)
		{
			if (ob_sprites[s].dist_to_player < 11)
				ob_sprites[s].state = 0;
			else
				ob_sprites[s].state = ob_sprites[s].prev_state;
		}
		s++;
	}
}

void	player_damage_lose(t_player *player, t_obj *osp, t_env *env)
{
	if (distance(player->x, player->y, osp->x, osp->y) < 12 && osp->alive)
	{
		player->damaged = SDL_TRUE;
		player->blood--;
		player->life = (SDL_Rect){40, W_H - 32, player->blood, 5};
		Mix_Resume(6);
	}
	else
	{
		Mix_Pause(6);
		player->damaged = SDL_FALSE;
	}
	if (player->blood < 0)
		env->screen = 5;
}
