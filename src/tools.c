/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:18:41 by amya              #+#    #+#             */
/*   Updated: 2022/05/18 12:10:19 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	dtor(float d)
{
	return (d * PI / 180.0f);
}

void	wr(t_env *env, char *str, t_p pos)
{
	SDL_Color		color;
	SDL_Surface		*surface_message;
	SDL_Texture		*message;
	SDL_Rect		message_rect;

	color = (SDL_Color){200, 100, 0, 255};
	surface_message = TTF_RenderText_Blended(env->font2, str, color);
	message = SDL_CreateTextureFromSurface(env->rend, surface_message);
	message_rect.x = pos.x;
	message_rect.y = pos.y;
	message_rect.w = surface_message->w;
	message_rect.h = surface_message->h;
	SDL_RenderCopy(env->rend, message, NULL, &message_rect);
	SDL_FreeSurface(surface_message);
	SDL_DestroyTexture(message);
}

void	fadding(t_env *env)
{
	SDL_Rect	r;

	if (env->fade > 0)
	{
		SDL_SetRenderDrawBlendMode(env->rend, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(env->rend, 0, 0, 0, env->fade);
		r = (SDL_Rect){0, 0, W_W, W_H};
		SDL_RenderFillRect(env->rend, &r);
		env->fade -= 10;
	}
}

float	safe_angle(float a)
{
	if (a > 2 * PI)
		a -= 2 * PI;
	if (a < 0)
		a += 2 * PI;
	return (a);
}

float	safe_angle_180(float a)
{
	if (a > PI)
		a -= PI;
	if (a < -PI)
		a += PI;
	return (a);
}
