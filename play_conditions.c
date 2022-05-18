/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:15:21 by amya              #+#    #+#             */
/*   Updated: 2022/05/17 17:17:38 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	player_sprite_cond(t_player *player, t_obj *ob_sprites, int s)
{
	if (player->x < ob_sprites[s].x && player->y < ob_sprites[s].y)
	{
		player->x -= (11 - ob_sprites[s].dist_to_player);
		player->y -= (11 - ob_sprites[s].dist_to_player);
	}
	if (player->x < ob_sprites[s].x && player->y > ob_sprites[s].y)
	{
		player->x -= (11 - ob_sprites[s].dist_to_player);
		player->y += (11 - ob_sprites[s].dist_to_player);
	}
	if (player->x > ob_sprites[s].x && player->y < ob_sprites[s].y)
	{
		player->x += (11 - ob_sprites[s].dist_to_player);
		player->y -= (11 - ob_sprites[s].dist_to_player);
	}
	if (player->x > ob_sprites[s].x && player->y > ob_sprites[s].y)
	{
		player->x += (11 - ob_sprites[s].dist_to_player);
		player->y += (11 - ob_sprites[s].dist_to_player);
	}
}
