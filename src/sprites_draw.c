/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:19:11 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:19:13 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	light_keys_l(t_my_doom *main, int x1, int k)
{
	if (0 < x1 && WIDTH > x1)
		if (main->duk_draw.mat.dr_bg - 1 < x1)
		{
			main->duk_draw.dr_sp.y1 = (370 + 0.3 * main->
					duk_draw.dr_sp.d_len) - (160 * main->dk_user.yaw);
			main->duk_draw.dr_sp.y2 = (main->duk_draw.mat.en_dr -
					main->duk_draw.mat.dr_bg) + (main->duk_draw.dr_sp.y1);
			v_line_card(main, x1, k);
		}
}

void	draw_sprt_key(t_my_doom *main, int k)
{
	float	cmps_tex;
	int		b;
	float	smpl_rat;

	main->duk_draw.mat.v = 0;
	main->duk_draw.mat.u = 0;
	smpl_rat = (float)52 / (float)(abs(main->duk_draw.mat.en_dr -
			main->duk_draw.mat.dr_bg));
	if (0.005 > smpl_rat)
		smpl_rat = 0.005;
	b = main->duk_draw.mat.dr_bg;
	cmps_tex = 0;
	while (main->duk_draw.mat.en_dr > b)
	{
		cmps_tex = smpl_rat + cmps_tex;
		main->duk_draw.mat.v = (int)cmps_tex;
		if (main->duk_draw.mat.v < 0 || 52 <= main->duk_draw.mat.v)
		{
			main->duk_draw.mat.v = 0;
			cmps_tex = 0;
		}
		light_keys_l(main, b, k);
		b++;
	}
}

void	light_item_line(t_my_doom *main, int x1, int some)
{
	if (x1 > 0 && x1 < WIDTH)
		if (main->duk_draw.mat.dr_bg - 1 < x1)
		{
			main->duk_draw.dr_sp.y1 = (370 + (0.3 *
					main->duk_draw.dr_sp.d_len))
				- (160 * main->dk_user.yaw);
			main->duk_draw.dr_sp.y2 = (main->duk_draw.mat.en_dr
				- main->duk_draw.mat.dr_bg) + main->duk_draw.dr_sp.y1;
			vline_item(main, x1, some);
		}
}

void	draw_item_sprite(t_my_doom *main, int some)
{
	float	smpl_rt;
	float	cmp_tex;
	int		b;

	main->duk_draw.mat.v = 0;
	main->duk_draw.mat.u = 0;
	smpl_rt = (float)100 / (float)(abs(main->duk_draw.mat.en_dr -
			main->duk_draw.mat.dr_bg));
	if (0.005 > smpl_rt)
		smpl_rt = 0.005;
	b = main->duk_draw.mat.dr_bg;
	cmp_tex = 0;
	while (main->duk_draw.mat.en_dr > b)
	{
		cmp_tex = smpl_rt + cmp_tex;
		main->duk_draw.mat.v = (int)cmp_tex;
		if (0 > main->duk_draw.mat.v || 100 <= main->duk_draw.mat.v)
		{
			main->duk_draw.mat.v = 0;
			cmp_tex = 0;
		}
		light_item_line(main, b, some);
		b++;
	}
}
