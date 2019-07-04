/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:48:04 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:48:06 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		fl_ceil_view(t_my_doom *d)
{
	d->duk_draw.mat.flo_y = d->duk_draw.mat.sect->floor - d->dk_user.where.z;
	d->duk_draw.mat.ce_y = d->duk_draw.mat.sect->ceil - d->dk_user.where.z;
	d->duk_draw.mat.dr_nei = d->duk_draw.mat.sect->n_bor[d->duk_draw.tini.s];
	d->duk_draw.mat.cel_ny = 0;
	d->duk_draw.mat.flo_ny = 0;
	if (0 <= d->duk_draw.mat.dr_nei)
	{
		if (0 <= d->duk_draw.mat.dr_nei)
		{
			d->duk_draw.mat.flo_ny = d->duk_sec[d->duk_draw.mat.dr_nei].floor
			- d->dk_user.where.z;
		}
		d->duk_draw.mat.cel_ny = d->duk_sec[d->duk_draw.mat.dr_nei].ceil
		- d->dk_user.where.z;
	}
}

void		proj_height(t_my_doom *d)
{
	d->duk_draw.mat.v = 0;
	d->duk_draw.mat.u = 0;
	d->duk_draw.mat.a1_y = HEIGHT / 2 - (int)(yaw(d, d->duk_draw.mat.ce_y,
		d->duk_draw.mat.z_1) * d->duk_draw.mat.scl_y1);
	d->duk_draw.mat.b1_y = HEIGHT / 2 - (int)(yaw(d, d->duk_draw.mat.flo_y,
		d->duk_draw.mat.z_1) * d->duk_draw.mat.scl_y1);
	d->duk_draw.mat.y2_a = HEIGHT / 2 - (int)(yaw(d, d->duk_draw.mat.ce_y,
		d->duk_draw.mat.z_2) * d->duk_draw.mat.scl_y2);
	d->duk_draw.mat.b2_y = HEIGHT / 2 - (int)(yaw(d, d->duk_draw.mat.flo_y,
		d->duk_draw.mat.z_2) * d->duk_draw.mat.scl_y2);
	d->duk_draw.mat.an_1 = HEIGHT / 2 - (int)(yaw(d, d->duk_draw.mat.cel_ny,
		d->duk_draw.mat.z_1) * d->duk_draw.mat.scl_y1);
	d->duk_draw.mat.bn_1 = HEIGHT / 2 - (int)(yaw(d, d->duk_draw.mat.flo_ny,
		d->duk_draw.mat.z_1) * d->duk_draw.mat.scl_y1);
	d->duk_draw.mat.an_2 = HEIGHT / 2 - (int)(yaw(d, d->duk_draw.mat.cel_ny,
		d->duk_draw.mat.z_2) * d->duk_draw.mat.scl_y2);
	d->duk_draw.mat.bn_2 = HEIGHT / 2 - (int)(yaw(d, d->duk_draw.mat.flo_ny,
		d->duk_draw.mat.z_2) * d->duk_draw.mat.scl_y2);
}

void		draw_ceil_floor(t_my_doom *d)
{
	d->duk_draw.mat.z = ((d->duk_draw.mat.x - d->duk_draw.mat.x1)
		* (d->duk_draw.mat.z_2 - d->duk_draw.mat.z_1)
		/ (d->duk_draw.mat.x2 - d->duk_draw.mat.x1)
		+ (d->duk_draw.mat.z_1)) * 0.6;
	d->duk_draw.mat.y_a = (d->duk_draw.mat.x - d->duk_draw.mat.x1)
	* (d->duk_draw.mat.y2_a - d->duk_draw.mat.a1_y)
		/ (d->duk_draw.mat.x2 - d->duk_draw.mat.x1)
		+ (d->duk_draw.mat.a1_y);
	d->duk_draw.mat.cy_a = clamp_float(d->duk_draw.mat.y_a,
		d->duk_draw.t_y[d->duk_draw.mat.x],
		d->duk_draw.botm_y[d->duk_draw.mat.x]);
	d->duk_draw.mat.y_b = (d->duk_draw.mat.x - d->duk_draw.mat.x1)
	* (d->duk_draw.mat.b2_y - d->duk_draw.mat.b1_y)
		/ (d->duk_draw.mat.x2 - d->duk_draw.mat.x1)
		+ (d->duk_draw.mat.b1_y);
	d->duk_draw.mat.cy_b = clamp_float(d->duk_draw.mat.y_b,
		d->duk_draw.t_y[d->duk_draw.mat.x],
		d->duk_draw.botm_y[d->duk_draw.mat.x]);
	tex_on_floor(d);
	tex_on_ceil(d);
}

void		lift_help_wall(t_my_doom *d)
{
	d->duk_draw.mat.a_ny = (d->duk_draw.mat.x - d->duk_draw.mat.x1)
	* (d->duk_draw.mat.an_2 - d->duk_draw.mat.an_1)
		/ (d->duk_draw.mat.x2 - d->duk_draw.mat.x1) + (d->duk_draw.mat.an_1);
	d->duk_draw.mat.a_nyc = clamp_float(d->duk_draw.mat.a_ny,
		d->duk_draw.t_y[d->duk_draw.mat.x],
		d->duk_draw.botm_y[d->duk_draw.mat.x]);
	d->duk_draw.mat.b_ny = (d->duk_draw.mat.x - d->duk_draw.mat.x1)
	* (d->duk_draw.mat.bn_2 - d->duk_draw.mat.bn_1)
		/ (d->duk_draw.mat.x2 - d->duk_draw.mat.x1) + (d->duk_draw.mat.bn_1);
	d->duk_draw.mat.b_nyc = clamp_float(d->duk_draw.mat.b_ny,
		d->duk_draw.t_y[d->duk_draw.mat.x],
		d->duk_draw.botm_y[d->duk_draw.mat.x]);
	d->duk_draw.t_y[d->duk_draw.mat.x] = clamp_float(f_max(d->duk_draw.mat.cy_a,
		d->duk_draw.mat.a_nyc), d->duk_draw.t_y[d->duk_draw.mat.x], HEIGHT - 1);
	d->duk_draw.botm_y[d->duk_draw.mat.x] =
	clamp_float(f_min(d->duk_draw.mat.cy_b,
		d->duk_draw.mat.b_nyc), 0, d->duk_draw.botm_y[d->duk_draw.mat.x]);
}

void		draw_walls_pic(t_my_doom *d)
{
	if (d->duk_draw.tini.i_win == 0 && 0 <= d->duk_draw.mat.dr_nei)
	{
		lift_help_wall(d);
		d->duk_draw.mat.a_ny = (d->duk_draw.mat.x - d->duk_draw.mat.x1)
		* (d->duk_draw.mat.an_2 - d->duk_draw.mat.an_1)
		/ (d->duk_draw.mat.x2 - d->duk_draw.mat.x1) + (d->duk_draw.mat.an_1);
		d->duk_draw.mat.a_nyc = clamp_float(d->duk_draw.mat.a_ny,
		d->duk_draw.t_y[d->duk_draw.mat.x],
		d->duk_draw.botm_y[d->duk_draw.mat.x]);
		d->duk_draw.mat.b_ny = (d->duk_draw.mat.x - d->duk_draw.mat.x1)
		* (d->duk_draw.mat.bn_2 - d->duk_draw.mat.bn_1)
		/ (d->duk_draw.mat.x2 - d->duk_draw.mat.x1) + (d->duk_draw.mat.bn_1);
		d->duk_draw.mat.b_nyc = clamp_float(d->duk_draw.mat.b_ny,
		d->duk_draw.t_y[d->duk_draw.mat.x],
		d->duk_draw.botm_y[d->duk_draw.mat.x]);
		d->duk_draw.t_y[d->duk_draw.mat.x] =
		clamp_float(f_max(d->duk_draw.mat.cy_a,
		d->duk_draw.mat.a_nyc), d->duk_draw.t_y[d->duk_draw.mat.x], HEIGHT - 1);
		d->duk_draw.botm_y[d->duk_draw.mat.x] =
		clamp_float(f_min(d->duk_draw.mat.cy_b,
		d->duk_draw.mat.b_nyc), 0, d->duk_draw.botm_y[d->duk_draw.mat.x]);
		draw_walls_pic_2(d);
	}
	else
		tex_on_wall(d);
}
