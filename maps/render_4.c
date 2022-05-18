/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:34:13 by amya              #+#    #+#             */
/*   Updated: 2022/05/18 13:35:06 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void     select_texture_rest(t_texture *t, t_env *env)
{
    if (t->num == 8)
        (t->img) = env->walls[6];
	if (t->num == 9)
		(t->img) = env->walls[7];
	if (t->num == 10)
		(t->img) = env->walls[8];
	if (t->num == 11)
		(t->img) = env->walls[9];
	if (t->num == 12)
		(t->img) = env->walls[10];
	if (t->num == 13)
		(t->img) = env->walls[11];
	if (t->num == 14)
		(t->img) = env->walls[12];
	if (t->num == 15)
		(t->img) = env->walls[13];
	if (t->num == 16)
		(t->img) = env->quit[env->frame_quit];
}

void	select_texture(t_texture *t, t_env *env)
{
	if (t->num == 1)
		(t->img) = env->walls[0];
	if (t->num == 2)
		(t->img) = env->doors[env->frame_door];
	if (t->num == 3)
		(t->img) = env->walls[1];
	if (t->num == 4)
		(t->img) = env->walls[2];
	if (t->num == 5)
		(t->img) = env->walls[3];
	if (t->num == 6)
		(t->img) = env->walls[4];
	if (t->num == 7)
		(t->img) = env->walls[5];
	select_texture_rest(t, env);
}
