/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fly_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:16:02 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:16:04 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		fly_mode_doom(t_my_doom *my)
{
	float nextz;

	if (my->duk_gm.n_fly == 1)
	{
		my->duk_gm.f_ng = 0;
		my->duk_gm.gr_d = 0;
		nextz = my->dk_user.where.z + my->dk_user.us_sp.z;
		fly_phys_doom(my, nextz);
		if (my->dk_user.where.z < my->duk_sec[my->dk_user.us_sec].floor
		+ my->duk_gm.n_eyht)
		{
			my->dk_user.where.z = my->duk_sec[my->dk_user.us_sec].floor
					+ my->duk_gm.n_eyht;
			my->dk_user.us_sp.z = 0;
		}
	}
}

void		hor_col_doom(t_my_doom *my, float d_x,
	float d_y, size_t n)
{
	float		xd;
	float		yd;
	float		dx_temp;

	if (my->duk_gm.m_ng == 1)
	{
		while (++n < my->duk_sec[my->dk_user.us_sec].num_p)
			if (bumps(my, d_x, d_y, n) == 1)
			{
				xd = my->duk_sec[my->dk_user.us_sec].d_top[n + 1].x
				- my->duk_sec[my->dk_user.us_sec].d_top[n + 0].x;
				yd = my->duk_sec[my->dk_user.us_sec].d_top[n + 1].y
				- my->duk_sec[my->dk_user.us_sec].d_top[n + 0].y;
				dx_temp = xd * (d_x * xd + yd * d_y) / (xd * xd + yd * yd);
				d_y = yd * (d_x * xd + yd * d_y) / (xd * xd + yd * yd);
				d_x = dx_temp;
				my->duk_gm.m_ng = 0;
			}
		doom_move_player(my, d_x, d_y);
		if (p_doom_map(my) != 1)
			doom_move_player(my, -d_x, -d_y);
		my->duk_gm.f_ng = (my->dk_user.invspr.jackpack == 0) ? 1 : 0;
	}
}
