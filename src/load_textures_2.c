/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:17:51 by yzemmour          #+#    #+#             */
/*   Updated: 2022/05/20 18:36:55 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_sprites_tex(t_env *env, SDL_Texture **tx_sprites)
{
	tx_sprites[0] = SDL_CreateTextureFromSurface(env->rend, env->sprites[0]);
	tx_sprites[1] = SDL_CreateTextureFromSurface(env->rend, env->sprites[1]);
	tx_sprites[2] = SDL_CreateTextureFromSurface(env->rend, env->sprites[2]);
	tx_sprites[3] = SDL_CreateTextureFromSurface(env->rend, env->sprites[3]);
	tx_sprites[4] = SDL_CreateTextureFromSurface(env->rend, env->sprites[4]);
	tx_sprites[5] = SDL_CreateTextureFromSurface(env->rend, env->sprites[5]);
	tx_sprites[6] = SDL_CreateTextureFromSurface(env->rend, env->sprites[6]);
	tx_sprites[7] = SDL_CreateTextureFromSurface(env->rend, env->sprites[7]);
}

void	load_decoration(t_decoration_surface *s)
{
	s->icon = IMG_Load("resources/images/decoration/sound.png");
	s->welcom_sc = IMG_Load("resources/images/decoration/welcom_sc.png");
	s->wolf3d = IMG_Load("resources/images/decoration/wolf3d.png");
	s->play = IMG_Load("resources/images/decoration/play.png");
	s->quit = IMG_Load("resources/images/decoration/quit.png");
	s->menu_icon = IMG_Load("resources/images/decoration/menu_icon.png");
	s->menu_sc = IMG_Load("resources/images/decoration/menu_sc.png");
	s->menu_btns = IMG_Load("resources/images/decoration/menu_buttons.png");
	s->options_pupop = IMG_Load("resources/images/decoration/opts_pupop.png");
	s->close_btn = IMG_Load("resources/images/decoration/close_btn.png");
	s->rust_code_sc = IMG_Load("resources/images/decoration/rust_code_sc.png");
	s->back_btn = IMG_Load("resources/images/decoration/back_btn.png");
	s->calculator = IMG_Load("resources/images/decoration/calculator.png");
	s->lose_sc = IMG_Load("resources/images/decoration/lose_sc.png");
	s->coin = IMG_Load("resources/images/sprites/coin.png");
	s->aim = IMG_Load("resources/images/decoration/aim.png");
	s->heart = IMG_Load("resources/images/decoration/heart.png");
	s->damage_sc = IMG_Load("resources/images/decoration/damage_sc.png");
}

void	create_decoration_texture(t_env *env, t_decor_texture *t,
	t_decoration_surface s)
{
	t->tx_icon_coin = SDL_CreateTextureFromSurface(env->rend, s.coin);
	t->tx_icon = SDL_CreateTextureFromSurface(env->rend, s.icon);
	t->tx_welcom_sc = SDL_CreateTextureFromSurface(env->rend, s.welcom_sc);
	t->tx_wolf3d = SDL_CreateTextureFromSurface(env->rend, s.wolf3d);
	t->tx_play = SDL_CreateTextureFromSurface(env->rend, s.play);
	t->tx_quit = SDL_CreateTextureFromSurface(env->rend, s.quit);
	t->tx_menu_icon = SDL_CreateTextureFromSurface(env->rend, s.menu_icon);
	t->tx_aim = SDL_CreateTextureFromSurface(env->rend, s.aim);
	t->tx_heart = SDL_CreateTextureFromSurface(env->rend, s.heart);
	t->tx_menu_sc = SDL_CreateTextureFromSurface(env->rend, s.menu_sc);
	t->tx_menu_btns = SDL_CreateTextureFromSurface(env->rend, s.menu_btns);
	t->tx_ops_pupop = SDL_CreateTextureFromSurface(env->rend, s.options_pupop);
	t->tx_close_btn = SDL_CreateTextureFromSurface(env->rend, s.close_btn);
	t->tx_code_sc = SDL_CreateTextureFromSurface(env->rend, s.rust_code_sc);
	t->tx_back_btn = SDL_CreateTextureFromSurface(env->rend, s.back_btn);
	t->tx_calculator = SDL_CreateTextureFromSurface(env->rend, s.calculator);
	t->tx_lose_sc = SDL_CreateTextureFromSurface(env->rend, s.lose_sc);
	t->tx_damage_sc = SDL_CreateTextureFromSurface(env->rend, s.damage_sc);
	env->floor = IMG_Load("resources/floor_derty.png");
	env->ceil = IMG_Load("resources/ceil.png");
	env->sky = IMG_Load("resources/night_sky.png");
}

void	load_beach2(t_env *env)
{
	env->beach[18] = IMG_Load("resources/images/beach/frame_18.png");
	env->beach[19] = IMG_Load("resources/images/beach/frame_19.png");
	env->beach[20] = IMG_Load("resources/images/beach/frame_20.png");
	env->beach[21] = IMG_Load("resources/images/beach/frame_21.png");
	env->beach[22] = IMG_Load("resources/images/beach/frame_22.png");
	env->beach[23] = IMG_Load("resources/images/beach/frame_23.png");
	env->beach[24] = IMG_Load("resources/images/beach/frame_24.png");
	env->beach[25] = IMG_Load("resources/images/beach/frame_25.png");
	env->beach[26] = IMG_Load("resources/images/beach/frame_26.png");
	env->beach[27] = IMG_Load("resources/images/beach/frame_27.png");
	env->beach[28] = IMG_Load("resources/images/beach/frame_28.png");
	env->beach[29] = IMG_Load("resources/images/beach/frame_29.png");
	env->beach[30] = IMG_Load("resources/images/beach/frame_30.png");
	env->beach[31] = IMG_Load("resources/images/beach/frame_31.png");
	env->beach[32] = IMG_Load("resources/images/beach/frame_32.png");
}

void	load_beach1(t_env *env)
{
	env->beach[0] = IMG_Load("resources/images/beach/frame_00.png");
	env->beach[1] = IMG_Load("resources/images/beach/frame_01.png");
	env->beach[2] = IMG_Load("resources/images/beach/frame_02.png");
	env->beach[3] = IMG_Load("resources/images/beach/frame_03.png");
	env->beach[4] = IMG_Load("resources/images/beach/frame_04.png");
	env->beach[5] = IMG_Load("resources/images/beach/frame_05.png");
	env->beach[6] = IMG_Load("resources/images/beach/frame_06.png");
	env->beach[7] = IMG_Load("resources/images/beach/frame_07.png");
	env->beach[8] = IMG_Load("resources/images/beach/frame_08.png");
	env->beach[9] = IMG_Load("resources/images/beach/frame_09.png");
	env->beach[10] = IMG_Load("resources/images/beach/frame_10.png");
	env->beach[11] = IMG_Load("resources/images/beach/frame_11.png");
	env->beach[12] = IMG_Load("resources/images/beach/frame_12.png");
	env->beach[13] = IMG_Load("resources/images/beach/frame_13.png");
	env->beach[14] = IMG_Load("resources/images/beach/frame_14.png");
	env->beach[15] = IMG_Load("resources/images/beach/frame_15.png");
	env->beach[16] = IMG_Load("resources/images/beach/frame_16.png");
	env->beach[17] = IMG_Load("resources/images/beach/frame_17.png");
	load_beach2(env);
}
