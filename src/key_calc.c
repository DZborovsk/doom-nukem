/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:01:20 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:01:22 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	move_key(t_my_doom *dat)
{
	if (dat->st_key[SDL_SCANCODE_W] || dat->st_key[SDL_SCANCODE_UP])
	{
		dat->duk_gm.n_pus = 1;
		dat->duk_gm.num_v[0] += dat->duk_gm.n_spd * dat->dk_user.cos_an;
		dat->duk_gm.num_v[1] += dat->duk_gm.n_spd * dat->dk_user.sin_an;
	}
	if (dat->st_key[SDL_SCANCODE_S] || dat->st_key[SDL_SCANCODE_DOWN])
	{
		dat->duk_gm.n_pus = 1;
		dat->duk_gm.num_v[0] -= dat->duk_gm.n_spd * dat->dk_user.cos_an;
		dat->duk_gm.num_v[1] -= dat->duk_gm.n_spd * dat->dk_user.sin_an;
	}
	if (dat->st_key[SDL_SCANCODE_D] || dat->st_key[SDL_SCANCODE_RIGHT])
	{
		dat->duk_gm.n_pus = 1;
		dat->duk_gm.num_v[0] -= dat->duk_gm.n_spd * dat->dk_user.sin_an;
		dat->duk_gm.num_v[1] += dat->duk_gm.n_spd * dat->dk_user.cos_an;
	}
	if (dat->st_key[SDL_SCANCODE_A] || dat->st_key[SDL_SCANCODE_LEFT])
	{
		dat->duk_gm.n_pus = 1;
		dat->duk_gm.num_v[0] += dat->duk_gm.n_spd * dat->dk_user.sin_an;
		dat->duk_gm.num_v[1] -= dat->duk_gm.n_spd * dat->dk_user.cos_an;
	}
}

void	jump_ctrl_key(t_my_doom *dat)
{
	dat->duk_gm.n_duc = 0;
	if (dat->st_key[SDL_SCANCODE_LCTRL])
	{
		dat->duk_gm.f_ng = 1;
		dat->duk_gm.n_duc = 1;
	}
	if (dat->duk_gm.n_pus)
	{
		dat->duk_gm.m_ng = 1;
	}
	if (dat->st_key[SDL_SCANCODE_SPACE])
	{
		if (dat->duk_gm.gr_d)
		{
			dat->dk_user.us_sp.z = 0.5 + dat->dk_user.us_sp.z;
			dat->duk_gm.f_ng = 1;
		}
	}
}

void	fly_key(t_my_doom *dat, SDL_Event event)
{
	if (SDLK_m == event.key.keysym.sym)
	{
		if (dat->md_d == 0)
		{
			dat->md_d = 1;
		}
		else
		{
			dat->md_d = 0;
		}
	}
	if (SDLK_j == event.key.keysym.sym)
	{
		if (dat->duk_gm.n_fly == 0)
		{
			dat->dk_user.us_sp.z = 0;
			dat->duk_gm.n_fly = 1;
		}
		else
		{
			dat->duk_gm.f_ng = 1;
			dat->duk_gm.n_fly = 0;
		}
	}
}

void	fly_key_2(t_my_doom *main, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_1)
		if (main->dk_user.invspr.wea_ph == 1)
			main->dk_user.invspr.i_we_tp = 1;
	if (event.key.keysym.sym == SDLK_2)
		if (main->dk_user.invspr.wea_ph == 1)
			main->dk_user.invspr.i_we_tp = 2;
	if (event.key.keysym.sym == SDLK_g)
		motion_lift(main);
	if (event.key.keysym.sym == SDLK_f)
		interact_door(main);
	if (event.key.keysym.sym == SDLK_n)
	{
		if (main->duk_gm.m_wi == 0)
			main->duk_gm.m_wi = 1;
		else
			main->duk_gm.m_wi = 0;
	}
	if (0 < main->dk_user.invspr.shine
		&& event.key.keysym.sym == SDLK_l)
	{
		if (main->duk_sec[main->dk_user.us_sec].light == 1)
			main->duk_sec[main->dk_user.us_sec].light = 0;
		else
			main->duk_sec[main->dk_user.us_sec].light = 1;
	}
}

void	main_keys_doom(t_my_doom *dat)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (SDL_QUIT == event.type)
			doom_quit(2, dat);
		if (SDL_MOUSEBUTTONDOWN == event.type)
			mouse_main(dat, event);
		if (SDL_KEYDOWN == event.type)
		{
			fly_key(dat, event);
			fly_key_2(dat, event);
		}
	}
	if (SDLK_p == event.key.keysym.sym)
	{
		if (dat->dk_user.invspr.gravity == 0)
			dat->dk_user.invspr.gravity = 1;
		else
			dat->dk_user.invspr.gravity = 0;
	}
	doom_physic(dat);
	move_key(dat);
	jump_ctrl_key(dat);
}
