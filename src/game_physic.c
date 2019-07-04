/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_physic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:04:24 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:04:26 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	doom_physic(t_my_doom *my)
{
	float speed_run;
	float speed_walk;
	float vel;

	speed_run = 0.45;
	speed_walk = 0.35;
	vel = 0.5;
	my->duk_gm.n_spd = speed_walk;
	if (my->st_key[SDL_SCANCODE_LSHIFT])
		my->duk_gm.n_spd = speed_run;
	my->duk_gm.n_pus = 0;
	my->duk_gm.num_v[0] = 0.f;
	my->duk_gm.num_v[1] = 0.f;
	(my->st_key[SDL_SCANCODE_ESCAPE]) ? doom_quit(2, my) : 0;
	if (my->duk_gm.n_fly == 1)
	{
		if (my->st_key[SDL_SCANCODE_KP_PLUS] &&
		my->dk_user.invspr.armor > 0)
		{
			my->dk_user.invspr.armor--;
			my->dk_user.us_sp.z += vel;
		}
		(my->st_key[SDL_SCANCODE_KP_MINUS]) ?
		my->dk_user.us_sp.z -= vel : 0;
	}
}

void	doom_ingame_meh(t_my_doom *my)
{
	float	i;
	float	j;
	int		min;

	i = 2.5;
	j = 6;
	min = -1;
	my->duk_gm.n_eyht = my->duk_gm.n_duc ? i : j;
	if (my->dk_user.invspr.gravity == 0)
		my->duk_gm.gr_d = !my->duk_gm.f_ng;
	fly_mode_doom(my);
	vert_col_doom(my);
	hor_col_doom(my, my->duk_gm.num_v[0], my->duk_gm.num_v[1], min);
	main_keys_doom(my);
	doom_main_keys(my);
	if (calc_dmg_doom(my) == min)
	{
		doom_died_msg(my);
		doom_quit(1, my);
	}
	my->duk_gm.p_dor > 0 ? check_door(my) : 0;
	my->duk_gm.p_lif > 0 ? doom_lift_check(my, 0) : 0;
}

void	doom_render_meh(t_my_doom *my)
{
	SDL_RenderClear(my->duk_ren);
	SDL_UpdateTexture(my->duk_txr, NULL, my->duk_draw.dr_img, WIDTH << 2);
	SDL_RenderCopy(my->duk_ren, my->duk_txr, NULL, NULL);
}
