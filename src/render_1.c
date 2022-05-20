/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:07:26 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/20 18:13:24 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_map_line(t_env *env, t_ray *ray, t_rend_vars *v)
{
	v->mx = (int)(ray->rx) / CELLS;
	v->my = (int)(ray->ry) / CELLS;
	v->mp = v->my * env->mps + v->mx;
}

void	vertical_line(t_env *env, t_ray *ray, t_texture *tex, t_player *player)
{
	env->v.dof = 0;
	ray->dist_v = 100000;
	ray->vx = player->x;
	ray->vy = player->y;
	v_direction(ray, &env->v, player, env);
	while (env->v.dof < env->mps)
	{
		init_map_line(env, ray, &env->v);
		if (env->v.mp > 0 && env->v.mp < env->mps * env->mps
			&& env->map[env->v.mp] >= 1)
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->dist_v = distance(player->x, player->y, ray->vx, ray->vy);
			env->v.dof = env->mps;
			tex->vmt = env->map[env->v.mp];
		}	
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			env->v.dof += 1;
		}
	}
}

void	horizontal_line(t_env *env, t_ray *ray, t_texture *tex, t_player *p)
{
	env->v.dof = 0;
	ray->dist_h = 100000;
	ray->hx = p->x;
	ray->hy = p->y;
	h_direction(ray, &env->v, p, env);
	while (env->v.dof < env->mps)
	{
		init_map_line(env, ray, &env->v);
		if (env->v.mp > 0 && env->v.mp < env->mps * env->mps
			&& env->map[env->v.mp] >= 1)
		{
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->dist_h = distance(p->x, p->y, ray->hx, ray->hy);
			env->v.dof = env->mps;
			tex->hmt = env->map[env->v.mp];
		}	
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			env->v.dof += 1;
		}
	}
}

void	render_rays(t_env *env, t_player *player)
{
	t_rend_vars	v;
	t_ray		ray;
	t_texture	tex;

	tex.vmt = 0;
	tex.hmt = 0;
	tex.img = env->walls[0];
	ray.ra = player->a + dtor(player->fov / 2);
	ray.num = 0;
	while (ray.num < NUMRAYS)
	{
		ray.ra = safe_angle(ray.ra);
		horizontal_line(env, &ray, &tex, player);
		vertical_line(env, &ray, &tex, player);
		ray.shade = 1;
		closer_line(env->rend, &ray, &tex);
		ray.ca = safe_angle(player->a - ray.ra);
		ray.dist *= cos(ray.ca);
		player->dist[ray.num] = ray.dist;
		render_view(env, player, ray, tex);
		ray.ra -= dtor(player->fov / W_W);
		ray.ra = safe_angle(ray.ra);
		ray.num++;
	}
}

void	render(t_env *env, t_player *player)
{
	if (env->skybox)
		draw_sky(env->rend, env->sky, player);
	render_rays(env, player);
	if (env->mps == 24)
		draw_sprite(env->rend, player, env->ob_sprites, env);
	if (env->minimap)
		render_map(env->rend, player, env->ob_sprites, env);
}
