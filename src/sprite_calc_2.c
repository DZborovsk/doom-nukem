/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calc_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:25:15 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:25:17 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		help_sqrt(t_my_doom *main)
{
	int res;

	main->obj++;
	main->time = SDL_GetTicks();
	main->flag = 0;
	res = main->duk_draw.mat.sect->sp_thi[main->duk_draw.dr_sp.n_spr].id_sp_d;
	main->duk_draw.mat.sect->sp_thi[main->duk_draw.dr_sp.n_spr].id_sp_d = -1;
	return (res);
}

int		calc_sprt_inter(t_my_doom *main)
{
	int r;

	if (main->duk_draw.dr_sp.d_len > 1 &&
		6 == main->duk_draw.mat.sect->sp_thi[main->duk_draw.dr_sp.n_spr].
				id_sp_d && main->duk_draw.dr_sp.d_len < 100)
	{
		pos_enemy(main);
	}
	if (5 > main->duk_draw.dr_sp.d_len &&
		6 == main->duk_draw.mat.sect->
				sp_thi[main->duk_draw.dr_sp.n_spr].id_sp_d)
	{
		main->time = SDL_GetTicks();
		main->flag = 1;
		main->dk_user.invspr.hp--;
	}
	else if (2 > main->duk_draw.dr_sp.d_len)
	{
		r = help_sqrt(main);
		return (r);
	}
	return (-1);
}
