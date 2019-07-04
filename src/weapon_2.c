/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:14:14 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:14:16 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			draw_weapon_s(t_my_doom *my, int pos_x,
		int yp, int i)
{
	int		h_x;
	int		w_y;
	int		i_x;
	float	num_x;
	float	num_y;

	w_y = 0;
	num_y = 0;
	while (w_y < 178 && yp < HEIGHT)
	{
		h_x = 0;
		num_x = 0;
		i_x = pos_x;
		while (h_x < 178 - 1 && i_x < WIDTH)
		{
			num_x += 0.38;
			h_x = (int)num_x;
			if (my->duk_draw.shun[i][w_y][h_x] != 0x000000)
				my->duk_draw.dr_img[yp][i_x] = my->duk_draw.shun[i][w_y][h_x];
			++i_x;
		}
		num_y += 0.38;
		w_y = (int)num_y;
		++yp;
	}
}

void			draw_shotgun(t_my_doom *my)
{
	if (my->dk_user.invspr.wea_ph == 1)
		draw_weapon_s(my, 450, 350, 0);
	else if (my->dk_user.invspr.wea_ph > 1)
	{
		draw_weapon_s(my, 450, 350,
				(int)my->dk_user.invspr.wea_ph - 1);
		my->dk_user.invspr.wea_ph += 0.2;
	}
	if (my->dk_user.invspr.wea_ph >= 10)
		my->dk_user.invspr.wea_ph = 1;
	else if (my->dk_user.invspr.wea_ph >= 4)
		my->dk_user.invspr.i_we_mh = 0;
}
