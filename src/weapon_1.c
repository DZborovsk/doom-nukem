/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:07:27 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 19:12:16 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		draw_weapon_p(t_my_doom *d, int pos_x, int l, int e)
{
	int		w_x;
	int		h_y;
	int		img_x;
	float	num_x;
	float	num_y;

	h_y = 0;
	num_y = 0;
	while (h_y < 128 && l < HEIGHT)
	{
		w_x = 0;
		num_x = 0;
		img_x = pos_x;
		while (w_x < 128 - 1 && img_x < WIDTH)
		{
			num_x += 0.38;
			w_x = (int)num_x;
			if (d->duk_draw.blast[e][h_y][w_x] != 0x000000)
				d->duk_draw.dr_img[l][img_x] = d->duk_draw.blast[e][h_y][w_x];
			++img_x;
		}
		num_y += 0.38;
		h_y = (int)num_y;
		++l;
	}
}

void		draw_walls_pic_2(t_my_doom *d)
{
	vline(d, set_point(d->duk_draw.mat.x, d->duk_draw.mat.cy_a,
		d->duk_draw.mat.a_nyc - 1), set_point(0, d->duk_draw.mat.x
		== d->duk_draw.mat.x1 || d->duk_draw.mat.x
		== d->duk_draw.mat.x2 ? 0 : d->duk_draw.mat.r1, 0));
	vline_tex(d, set_point(d->duk_draw.mat.x, d->duk_draw.mat.cy_a,
		d->duk_draw.mat.a_nyc - 1), 3);
	vline_tex(d, set_point(d->duk_draw.mat.x, d->duk_draw.mat.b_nyc + 1,
		d->duk_draw.mat.cy_b), 1);
}

void		draw_pistol_an(t_my_doom *main)
{
	if (main->dk_user.invspr.wea_ph == 1)
		draw_weapon_p(main, 600, HEIGHT - 350, 0);
	else if (main->dk_user.invspr.wea_ph > 1)
	{
		draw_weapon_p(main, 600, HEIGHT - 350,
				(int)main->dk_user.invspr.wea_ph - 1);
		main->dk_user.invspr.wea_ph += 0.5;
	}
	if (main->dk_user.invspr.wea_ph >= 7)
		main->dk_user.invspr.wea_ph = 1;
	if (main->dk_user.invspr.wea_ph >= 3)
		main->dk_user.invspr.i_we_mh = 0;
}
