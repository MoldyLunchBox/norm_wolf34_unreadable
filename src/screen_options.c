/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:02:09 by amya              #+#    #+#             */
/*   Updated: 2022/05/20 18:39:07 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	screen_options(t_env *env, t_rect_decor *rd)
{
	if (env->options_pupop_showed == 1)
	{
		SDL_RenderCopy(env->rend, env->t.tx_ops_pupop,
			&env->rd.rect_options_pupop_s, &env->rd.rect_options_pupop_d);
		SDL_RenderCopy(env->rend, env->t.tx_close_btn,
			&env->rd.rect_close_btn_s, &env->rd.rect_close_btn_d);
	}
}
