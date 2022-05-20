/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:00:28 by amya              #+#    #+#             */
/*   Updated: 2022/05/20 18:13:24 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	aid_static(t_obj *osprites, SDL_Texture **tsprites, t_env *env)
{
	init_obj(&osprites[17], (t_vars_obj){2 * CELLS + 10, 22 * CELLS
		+ 10, 223, 200, 4, 4, 4, 0, 223, 4}, tsprites[5]);
	init_obj(&osprites[0], (t_vars_obj){12 * CELLS + 10, 12 * CELLS + 10,
		820, 1694, 1, 2, 1, 0, 820, 1}, tsprites[0]);
	init_obj(&osprites[1], (t_vars_obj){3 * CELLS + 10, 2 * CELLS, 280,
		270, 1, 3, 3, 0, 280, 1}, tsprites[1]);
	init_obj(&osprites[2], (t_vars_obj){10 * CELLS + 10, 7 * CELLS + 10,
		260, 310, 1, 3, 3, 0, 260, 1}, tsprites[6]);
	init_obj(&osprites[3], (t_vars_obj){15 * CELLS + 10, 7 * CELLS + 10,
		900, 900, 5, 2, 3, 0, 900, 5}, tsprites[7]);
	init_obj(&osprites[4], (t_vars_obj){15 * CELLS + 10, 7 * CELLS + 10,
		295, 400, 1, 3, 3, 0, 295, 1}, tsprites[4]);
}

void	sprites_en(t_obj *osprites, SDL_Texture **tsprites, t_env *env)
{
	init_obj(&osprites[5], (t_vars_obj){0 * CELLS, 0 * CELLS,
		910, 1493, 2, 3, 2, 0, 910, 2}, tsprites[2]);
	init_obj(&osprites[6], (t_vars_obj){16 * CELLS, 4 * CELLS, 910,
		1493, 2, 3, 2, 3, 910, 2}, tsprites[2]);
	init_obj(&osprites[7], (t_vars_obj){2 * CELLS, 15 * CELLS, 910,
		1493, 2, 3, 2, 6, 910, 2}, tsprites[2]);
	init_obj(&osprites[8], (t_vars_obj){3 * CELLS, 13 * CELLS, 910,
		1493, 2, 3, 2, 8, 910, 2}, tsprites[2]);
	init_obj(&osprites[9], (t_vars_obj){1 * CELLS + 10, 19 * CELLS + 10,
		910, 1493, 2, 3, 2, 0, 910, 2}, tsprites[2]);
	init_obj(&osprites[10], (t_vars_obj){8 * CELLS, 22 * CELLS + 10, 910,
		1493, 2, 3, 2, 3, 910, 2}, tsprites[2]);
	init_obj(&osprites[11], (t_vars_obj){18 * CELLS, 20 * CELLS + 10, 910,
		1493, 2, 3, 2, 6, 910, 2}, tsprites[2]);
	init_obj(&osprites[12], (t_vars_obj){22 * CELLS + 10, 3 * CELLS + 10,
		910, 1493, 2, 3, 2, 8, 910, 2}, tsprites[2]);
	init_obj(&osprites[13], (t_vars_obj){22 * CELLS + 10, 7 * CELLS + 10,
		910, 1493, 2, 3, 2, 0, 910, 2}, tsprites[2]);
	init_obj(&osprites[14], (t_vars_obj){13 * CELLS, 13 * CELLS + 10, 910,
		1493, 2, 3, 2, 3, 910, 2}, tsprites[2]);
	init_obj(&osprites[15], (t_vars_obj){7 * CELLS + 10, 1 * CELLS + 10, 910,
		1493, 2, 3, 2, 6, 910, 2}, tsprites[2]);
	init_obj(&osprites[16], (t_vars_obj){10 * CELLS + 10, 16 * CELLS + 10, 910,
		1493, 2, 3, 2, 8, 910, 2}, tsprites[2]);
}

void	sp_coin(t_obj *osprites, SDL_Texture **tsprites, t_env *env)
{
	init_obj(&osprites[18], (t_vars_obj){9 * CELLS + 10, 1 * CELLS
		+ 7, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[19], (t_vars_obj){9 * CELLS + 20, 1 * CELLS
		+ 7, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[20], (t_vars_obj){9 * CELLS + 30, 1 * CELLS
		+ 7, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[21], (t_vars_obj){9 * CELLS + 40, 1 * CELLS
		+ 7, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[22], (t_vars_obj){9 * CELLS + 10, 1 * CELLS
		+ 22, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[23], (t_vars_obj){9 * CELLS + 20, 1 * CELLS
		+ 22, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[24], (t_vars_obj){9 * CELLS + 30, 1 * CELLS
		+ 22, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[25], (t_vars_obj){9 * CELLS + 40, 1 * CELLS
		+ 22, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[26], (t_vars_obj){9 * CELLS + 10, 1 * CELLS
		+ 37, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[27], (t_vars_obj){9 * CELLS + 20, 1 * CELLS
		+ 37, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[28], (t_vars_obj){9 * CELLS + 30, 1 * CELLS
		+ 37, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
	init_obj(&osprites[29], (t_vars_obj){9 * CELLS + 40, 1 * CELLS
		+ 37, 512, 512, 3, 5, 5, 0, 512, 3}, tsprites[3]);
}

void	coin_rest(t_obj *osprite, SDL_Texture **tsprite, t_env *env)
{
	init_obj(&osprite[30], (t_vars_obj){9 * CELLS + 10, 1 * CELLS
		+ 52, 512, 512, 3, 5, 5, 0, 512, 3}, tsprite[3]);
	init_obj(&osprite[31], (t_vars_obj){9 * CELLS + 20, 1 * CELLS
		+ 52, 512, 512, 3, 5, 5, 0, 512, 3}, tsprite[3]);
	init_obj(&osprite[32], (t_vars_obj){9 * CELLS + 30, 1 * CELLS
		+ 52, 512, 512, 3, 5, 5, 0, 512, 3}, tsprite[3]);
	init_obj(&osprite[33], (t_vars_obj){9 * CELLS + 40, 1 * CELLS
		+ 52, 512, 512, 3, 5, 5, 0, 512, 3}, tsprite[3]);
	init_obj(&osprite[34], (t_vars_obj){17 * CELLS + 10, 11 * CELLS
		+ 10, 820, 1694, 1, 2, 1, 0, 820, 1}, tsprite[0]);
	init_obj(&osprite[35], (t_vars_obj){17 * CELLS + 10, 12 * CELLS
		+ 10, 820, 1694, 1, 2, 1, 0, 820, 1}, tsprite[0]);
	init_obj(&osprite[36], (t_vars_obj){17 * CELLS + 10, 13 * CELLS
		+ 10, 820, 1694, 1, 2, 1, 0, 820, 1}, tsprite[0]);
	init_obj(&osprite[37], (t_vars_obj){17 * CELLS + 10, 14 * CELLS
		+ 10, 820, 1694, 1, 2, 1, 0, 820, 1}, tsprite[0]);
}

void	sprites_reset(t_obj *osprite, SDL_Texture **tsprite, t_env *env)
{
	int	s;

	s = 0;
	while (s < env->num_sprites)
	{
		osprite[s].id = s;
		s++;
	}
	aid_static(osprite, tsprite, env);
	sprites_en(osprite, tsprite, env);
	sp_coin(osprite, tsprite, env);
	coin_rest(osprite, tsprite, env);
}
