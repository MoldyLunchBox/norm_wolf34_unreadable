/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init_rect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:13:03 by amya              #+#    #+#             */
/*   Updated: 2022/05/18 14:14:23 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_rect_sprite(t_obj *o_s, t_rec *rec, t_sp_vision *vars)
{
	rec->rect0 = (SDL_Rect){o_s->frame_width * o_s->frame_num
		+ ((float)o_s->surface_w / o_s->w
			* (vars->j - (int)vars->sx)), o_s->frame_higth * o_s->row,
		(float)o_s->surface_w / o_s->w, o_s->frame_higth};
	rec->rect1 = (SDL_Rect){vars->j, W_H / 2
		+ vars->on_floor - o_s->h, 1, o_s->h};
}
