/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:07:26 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/18 12:22:33 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	vertical_line(t_env *env, t_rend_vars *v, t_player *p)
{
	v->dof = 0;
	env->ray->dist_v = 100000;
	env->ray->vx = p->x;
	env->ray->vy = p->y;
	v_direction(env->ray, v, p, env);
	while (v->dof < env->mps)
	{
		v->mx = (int)(env->ray->rx) / cellS;
		v->my = (int)(env->ray->ry) / cellS;
		v->mp = v->my * env->mps + v->mx;
		if (v->mp > 0 && v->mp < env->mps * env->mps && env->map[v->mp] >= 1)
		{
			env->ray->vx = env->ray->rx;
			env->ray->vy = env->ray->ry;
			env->ray->dist_v = distance(p->x, p->y, env->ray->vx, env->ray->vy);
			v->dof = env->mps;
			env->tex->vmt = env->map[v->mp];
		}	
		else
		{
			env->ray->rx += env->ray->xo;
			env->ray->ry += env->ray->yo;
			v->dof += 1;
		}
	}
}

void	horizontal_line(t_env *env, t_rend_vars *v, t_player *p)
{
	v->dof = 0;
	env->ray->dist_h = 100000;
	env->ray->hx = p->x;
	env->ray->hy = p->y;
	h_direction(env->ray, v, p, env);
	while (v->dof < env->mps)
	{
		v->mx = (int)(env->ray->rx) / cellS;
		v->my = (int)(env->ray->ry) / cellS;
		v->mp = v->my * env->mps + v->mx;
		if (v->mp > 0 && v->mp < env->mps * env->mps && env->map[v->mp] >= 1)
		{
			env->ray->hx = env->ray->rx;
			env->ray->hy = env->ray->ry;
			env->ray->dist_h = distance(p->x, p->y, env->ray->hx, env->ray->hy);
			v->dof = env->mps;
			env->tex->hmt = env->map[v->mp];
		}	
		else
		{
			env->ray->rx += env->ray->xo;
			env->ray->ry += env->ray->yo;
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
	while (ray.num < numRays)
	{
		ray.ra = safe_angle(ray.ra);
		horizontal_line(env, &v, player);
		vertical_line(env, &v, player);
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
