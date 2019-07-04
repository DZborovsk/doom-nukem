/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:19:48 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:19:50 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			player_calc_view(t_my_doom *d)
{
	d->duk_draw.mat.v1x = d->duk_draw.mat.sect->d_top[d->duk_draw.tini.s + 0].x
		- d->dk_user.where.x;
	d->duk_draw.mat.v1y = d->duk_draw.mat.sect->d_top[d->duk_draw.tini.s + 0].y
		- d->dk_user.where.y;
	d->duk_draw.mat.v2x = d->duk_draw.mat.sect->d_top[d->duk_draw.tini.s + 1].x
		- d->dk_user.where.x;
	d->duk_draw.mat.v2y = d->duk_draw.mat.sect->d_top[d->duk_draw.tini.s + 1].y
		- d->dk_user.where.y;
	d->duk_draw.mat.c_p = d->dk_user.cos_an;
	d->duk_draw.mat.s_p = d->dk_user.sin_an;
	d->duk_draw.mat.t_1 = d->duk_draw.mat.v1x * d->duk_draw.mat.s_p
		- d->duk_draw.mat.v1y * d->duk_draw.mat.c_p;
	d->duk_draw.mat.z_1 = d->duk_draw.mat.v1x * d->duk_draw.mat.c_p
		+ d->duk_draw.mat.v1y * d->duk_draw.mat.s_p;
	d->duk_draw.mat.t_2 = d->duk_draw.mat.v2x * d->duk_draw.mat.s_p
		- d->duk_draw.mat.v2y * d->duk_draw.mat.c_p;
	d->duk_draw.mat.z_2 = d->duk_draw.mat.v2x * d->duk_draw.mat.c_p
		+ d->duk_draw.mat.v2y * d->duk_draw.mat.s_p;
}

static void		wall_int_check(t_my_doom *d)
{
	if (d->duk_draw.mat.z_nea > d->duk_draw.mat.z_2)
	{
		d->duk_draw.mat.t_2 = d->duk_draw.mat.i2.x;
		d->duk_draw.mat.z_2 = d->duk_draw.mat.i2.y;
		if (d->duk_draw.mat.i1.y > 0)
		{
			d->duk_draw.mat.z_2 = d->duk_draw.mat.i1.y;
			d->duk_draw.mat.t_2 = d->duk_draw.mat.i1.x;
		}
	}
	if (d->duk_draw.mat.z_nea > d->duk_draw.mat.z_1)
	{
		d->duk_draw.mat.t_1 = d->duk_draw.mat.i2.x;
		d->duk_draw.mat.z_1 = d->duk_draw.mat.i2.y;
		if (0 < d->duk_draw.mat.i1.y)
		{
			d->duk_draw.mat.z_1 = d->duk_draw.mat.i1.y;
			d->duk_draw.mat.t_1 = d->duk_draw.mat.i1.x;
		}
	}
}

void			wall_intersec(t_my_doom *d)
{
	if (d->duk_draw.mat.z_2 <= 0 || d->duk_draw.mat.z_1 <= 0)
	{
		d->duk_draw.mat.s_nea = 1e-5f;
		d->duk_draw.mat.z_f = 5;
		d->duk_draw.mat.z_nea = 1e-4f;
		d->duk_draw.mat.sd_fa = 20.f;
		if (d->duk_draw.mat.z_2 <= 0 || d->duk_draw.mat.z_1 <= 0)
		{
			d->duk_draw.mat.i1 =
			doom_inter_sect(ft_map_help(d->duk_draw.mat.t_1,
			d->duk_draw.mat.z_1, d->duk_draw.mat.t_2),
			ft_map_help(d->duk_draw.mat.z_2, -d->duk_draw.mat.s_nea,
			d->duk_draw.mat.z_nea), -d->duk_draw.mat.sd_fa,
			d->duk_draw.mat.z_f);
		}
		if (d->duk_draw.mat.z_2 <= 0 || d->duk_draw.mat.z_1 <= 0)
		{
			d->duk_draw.mat.i2 =
			doom_inter_sect(ft_map_help(d->duk_draw.mat.t_1,
			d->duk_draw.mat.z_1, d->duk_draw.mat.t_2),
			ft_map_help(d->duk_draw.mat.z_2, d->duk_draw.mat.s_nea,
			d->duk_draw.mat.z_nea), d->duk_draw.mat.sd_fa, d->duk_draw.mat.z_f);
		}
		wall_int_check(d);
	}
}

void			perspect_trans(t_my_doom *d)
{
	float	h_res;
	float	v_res;

	h_res = (0.73f * HEIGHT);
	v_res = (0.2f * HEIGHT);
	d->duk_draw.mat.scl_y1 = v_res / d->duk_draw.mat.z_1;
	d->duk_draw.mat.scl_x1 = h_res / d->duk_draw.mat.z_1;
	d->duk_draw.mat.x1 = WIDTH / 2
	- (int)(d->duk_draw.mat.t_1 * d->duk_draw.mat.scl_x1);
	d->duk_draw.mat.scl_y2 = v_res / d->duk_draw.mat.z_2;
	d->duk_draw.mat.scl_x2 = h_res / d->duk_draw.mat.z_2;
	d->duk_draw.mat.x2 = WIDTH / 2
	- (int)(d->duk_draw.mat.t_2 * d->duk_draw.mat.scl_x2);
}
