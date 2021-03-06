/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:14:16 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/20 18:13:24 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

Uint32	getpixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (x >= surface->w)
		x = surface->w -1;
	if (y >= surface->h)
		y = surface->h -1;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16 *)p);
	else if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (bpp == 4)
		return (*(Uint32 *)p);
	else
		return (0);
}

float	range_conv_val(t_pnt old, t_pnt new, float old_value)
{
	float	old_range;
	float	new_range;
	float	new_value;

	old_range = (old.ma - old.mi);
	new_range = (new.ma - new.mi);
	new_value = (((old_value - old.mi) * new_range) / old_range) + new.mi;
	return (new_value);
}

void	color_fix(t_color *c)
{
	if (c->red > 255)
		c->red = 255;
	if (c->red < 0)
		c->red = 0;
	if (c->green > 255)
		c->green = 255;
	if (c->green < 0)
		c->green = 0;
	if (c->blue > 255)
		c->blue = 255;
	if (c->blue < 0)
		c->blue = 0;
}

void	safe_map(t_player *player, float pdx, float pdy, t_env *env)
{	
	t_var_int	vars;

	vars.x0 = 0;
	vars.y0 = 0;
	if (pdx < 0)
		vars.x0 = -WALL_PADDING;
	else
		vars.x0 = WALL_PADDING;
	if (pdy < 0)
		vars.y0 = -WALL_PADDING;
	else
		vars.y0 = WALL_PADDING;
	vars.ipx = player->x / CELLS;
	vars.ipx_add_x0 = (player->x + vars.x0) / CELLS;
	vars.ipx_sub_x0 = (player->x - vars.x0) / CELLS;
	vars.ipy = player->y / CELLS;
	vars.ipy_add_y0 = (player->y + vars.y0) / CELLS;
	vars.ipy_sub_y0 = (player->y - vars.y0) / CELLS;
	if ((vars.ipy * env->mps + vars.ipx_add_x0 != 0
			&& env->map[vars.ipy * env->mps + vars.ipx_add_x0] == 0))
		player->x += pdx * player->speed;
	if ((vars.ipy_add_y0 * env->mps + vars.ipx != 0
			&& env->map[vars.ipy_add_y0 * env->mps + vars.ipx] == 0))
		player->y += pdy * player->speed;
}
