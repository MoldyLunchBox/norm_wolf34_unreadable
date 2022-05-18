/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:16:49 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/18 14:10:46 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texture_cords(t_texture *t, t_ray *r, float *line_h)
{
	t->ty_step = (t->img)->w / (float)*line_h;
	t->ty_offset = 0;
	if (*line_h > W_H)
	{
		t->ty_offset = (*line_h - W_H) / 2.0;
		*line_h = W_H;
	}	
	if (*line_h <= 0)
		*line_h = 1;
	t->ty = t->ty_offset * t->ty_step;
	t->scaling = (float)(t->img)->w / cellS;
	if (r->shade == 1)
	{
		t->tx = (int)(r->rx * t->scaling) % (t->img)->w;
		if (r->ra > PI)
			t->tx = ((t->img)->w - 1) - t->tx;
	}
	else
	{
		t->tx = (int)(r->ry * t->scaling) % (t->img)->w;
		if (r->ra > PI / 2 && r->ra < (3 * PI) / 2)
			t->tx = ((t->img)->w - 1) - t->tx;
	}
}

void	h_direction(t_ray *ray, t_rend_vars *v, t_player *player, t_env *env)
{
	float	a_tan;

	if (ray->ra != 0. && ray->ra != PI)
	{
		a_tan = 1 / (tan(ray->ra));
		if (ray->ra < PI)
		{
			ray->ry = (((int)(player->y) / cellS) * cellS - 0.0001);
			ray->rx = player->x - (ray->ry - player->y) * a_tan;
			ray->yo = -(cellS);
			ray->xo = -ray->yo * a_tan;
		}
		if (ray->ra > PI)
		{
			ray->ry = (((int)(player->y) / cellS) * cellS) + cellS;
			ray->rx = player->x - (ray->ry - player->y) * a_tan;
			ray->yo = cellS;
			ray->xo = -ray->yo * a_tan;
		}
	}
	else
	{
		ray->rx = player->x;
		ray->ry = player->y;
		v->dof = env->mps;
	}
}

void	v_direction(t_ray *ray, t_rend_vars *v, t_player *player, t_env *env)
{
	float	a_tan;

	a_tan = tan(ray->ra);
	if (ray->ra > PI / 2 && ray->ra < (3 * PI) / 2)
	{
		ray->rx = (((int)(player->x) / cellS) * cellS - 0.0001);
		ray->ry = player->y - (ray->rx - player->x) * a_tan;
		ray->xo = -(cellS);
		ray->yo = -ray->xo * a_tan;
	}
	if (ray->ra < PI / 2 || ray->ra > (3 * PI) / 2)
	{
		ray->rx = (((int)(player->x) / cellS) * cellS) + cellS;
		ray->ry = player->y - (ray->rx - player->x) * a_tan;
		ray->xo = cellS;
		ray->yo = -ray->xo * a_tan;
	}
	if (ray->ra == 0. || ray->ra == PI)
	{
		ray->rx = player->x;
		ray->ry = player->y;
		v->dof = env->mps;
	}
}

void	render_view(t_env *env, t_player *player, t_ray r, t_texture t)
{
	float		line_h;
	SDL_Rect	line;
	int			y;

	line.w = W_W / numRays;
	line.x = r.num * line.w;
	line.h = 1;
	line_h = (WALL_H * 220) / r.dist;
	select_texture(&t, env->walls, env->quit, env->doors, env);
	texture_cords(&t, &r, &line_h);
	rend_wall(env->rend, &r, &t, line_h, env, &line);
	y = (W_H / 2) + (line_h / 2);
	while (y < W_H)
	{
		rend_floor(env->rend, &r, &t, env, &line, y, player, env->floor);
		rend_ceil(env->rend, &r, &t, env, &line, y, player, env->ceil);
		y++;
	}
}

void	closer_line(SDL_Renderer *rend, t_ray *ray, t_texture *tex)
{
	if (ray->dist_v < ray->dist_h)
	{
		tex->num = tex->vmt;
		ray->shade = 0.5;
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->dist = ray->dist_v;
		if (ray->ra >= PI / 2 && ray->ra <= (3 * PI) / 2)
			SDL_SetRenderDrawColor(rend, 0, 0, 150, 255);
		else
			SDL_SetRenderDrawColor(rend, 0, 150, 0, 255);
	}
	if (ray->dist_h < ray->dist_v)
	{
		tex->num = tex->hmt;
		ray->rx = ray->hx;
		ray->ry = ray->hy;
		ray->dist = ray->dist_h;
		if (ray->ra <= PI)
			SDL_SetRenderDrawColor(rend, 200, 0, 200, 255);
		else
			SDL_SetRenderDrawColor(rend, 200, 200, 0, 255);
	}
}
