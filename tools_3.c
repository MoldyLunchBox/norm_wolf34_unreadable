/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:18:39 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/18 12:10:19 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_square(SDL_Renderer *rend, int size, int x, int y)
{
	int	ix;
	int	iy;
	int	i;

	i = 0;
	ix = x - size / 2;
	iy = y - size / 2;
	while (i < size)
	{
		SDL_RenderDrawLine(rend, ix, iy, ix + size, iy);
		iy++;
		i++;
	}
}

void	cursor_mouse(t_env *env)
{
	if (env->screen == 2 && env->cursor)
		SDL_ShowCursor(SDL_DISABLE);
	else
		SDL_ShowCursor(SDL_ENABLE);
}

void	create_obj(t_obj *obj)
{
	obj = (t_obj *)malloc(sizeof(t_obj));
}
