/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:07:26 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/20 18:09:01 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	vertical_line(t_env *env, t_ray *ray, t_texture *tex, t_rend_vars *v, t_player *player)
{
	v->dof = 0;
	ray->dist_v = 100000;
	ray->vx = player->x;
	ray->vy = player->y;
	v_direction(ray, v, player, env);
	while (v->dof < env->mps)
	{
		v->mx = (int)(ray->rx) / cellS;
		v->my = (int)(ray->ry) / cellS;
		v->mp = v->my * env->mps + v->mx;
		if (v->mp > 0 && v->mp < env->mps * env->mps && env->map[v->mp] >= 1)
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->dist_v = distance(player->x, player->y, ray->vx, ray->vy);
			v->dof = env->mps;
			tex->vmt = env->map[v->mp];
		}	
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			v->dof += 1;
		}
	}
}

void	horizontal_line(t_env *env, t_ray *ray, t_texture *tex, t_rend_vars *v, t_player *player)
{
	v->dof = 0;
	ray->dist_h = 100000;
	ray->hx = player->x;
	ray->hy = player->y;
	h_direction(ray, v, player, env);
	while (v->dof < env->mps)
	{
		v->mx = (int)(ray->rx) / cellS;
		v->my = (int)(ray->ry) / cellS;
		v->mp = v->my * env->mps + v->mx;
		if (v->mp > 0 && v->mp < env->mps * env->mps && env->map[v->mp] >= 1)
		{
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->dist_h = distance(player->x, player->y, ray->hx, ray->hy);
			v->dof = env->mps;
			tex->hmt = env->map[v->mp];
		}	
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			v->dof += 1;
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
		horizontal_line(env, &ray, &tex, &v, player);
		vertical_line(env, &ray, &tex, &v, player);
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
