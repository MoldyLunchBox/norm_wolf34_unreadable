/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:19:52 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/20 18:13:24 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rend_floor(t_ray *r, t_texture *t, t_env *env, t_player *player)
{
	float		darkness;
	float		dy;
	float		ra_fix;
	SDL_Color	rgb;
	Uint32		data;

	darkness = range_conv_val((t_pnt){W_H, (W_H / 2)}, (t_pnt){1, 0}, env->y);
	env->line.y = env->y;
	dy = env->y - (W_H / 2.0);
	r->ra = safe_angle(r->ra);
	ra_fix = cos(player->a - r->ra);
	t->tx = player->x * 28 + cos(r->ra) * 220 * env->floor->w / dy / ra_fix;
	t->ty = player->y * 28 - sin(r->ra) * 220 * env->floor->w / dy / ra_fix;
	SDL_SetRenderDrawColor(env->rend, 200, 100, 50, 255);
	if (env->texture)
	{
		data = getpixel(env->floor, (int)(t->tx)
				& (env->floor->w - 1), (int)(t->ty) & (env->floor->w - 1));
		SDL_GetRGB(data, env->floor->format, &rgb.r, &rgb.g, &rgb.b);
		SDL_SetRenderDrawColor(env->rend, rgb.r * darkness, rgb.g * darkness,
			rgb.b * darkness, 255);
	}
	SDL_RenderFillRect(env->rend, &env->line);
}

void	rend_ceil(t_ray *r, t_texture *t, t_env *env, t_player *player)
{
	float		darkness;
	SDL_Color	rgb;
	Uint32		data;

	darkness = range_conv_val((t_pnt){W_H, (W_H / 2)}, (t_pnt){1, 0}, env->y);
	env->line.y = (W_H / 2.0) - (env->y - (W_H / 2.0)) - 1;
	SDL_SetRenderDrawColor(env->rend, 150, 150, 200, 255);
	if (env->texture && !env->skybox)
	{
		data = getpixel(env->ceil, (int)(t->tx)
				& (env->ceil->w - 1), (int)(t->ty) & (env->ceil->w - 1));
		SDL_GetRGB(data, env->ceil->format, &rgb.r, &rgb.g, &rgb.b);
		SDL_SetRenderDrawColor(env->rend, rgb.r * darkness, rgb.g * darkness,
			rgb.b * darkness, 255);
		SDL_RenderFillRect(env->rend, &env->line);
	}
	if (!env->texture)
		SDL_RenderFillRect(env->rend, &env->line);
}

void	wall_with_texture(SDL_Renderer *rend, t_ray *r, t_texture *t)
{
	t_color			c;
	float			darkness;
	SDL_Color		rgb;
	unsigned int	data;

	darkness = range_conv_val((t_pnt){CELLS * 24, 0},
			(t_pnt){0, 1}, r->dist);
	if (t->num == 2)
		r->shade = 1;
	data = getpixel((t->img), (int)(t->tx), (int)(t->ty));
	SDL_GetRGB(data, (t->img)->format, &rgb.r, &rgb.g, &rgb.b);
	c = (t_color){rgb.r * r->shade * darkness, rgb.g * r->shade * darkness,
		rgb.b * r->shade * darkness};
	color_fix(&c);
	SDL_SetRenderDrawColor(rend, c.red, c.green, c.blue, 255);
}

void	rend_wall(t_ray *r, t_texture *t, double line_h, t_env *env)
{
	int	y;

	y = 0;
	while (y < line_h)
	{
		env->line.y = (W_H / 2) - (line_h / 2) + y;
		if (env->texture)
			wall_with_texture(env->rend, r, t);
		SDL_RenderFillRect(env->rend, &env->line);
		t->ty += t->ty_step;
		y++;
	}
}
