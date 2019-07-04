/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:12:38 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 19:12:49 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			s_neighbor(t_my_doom *d)
{
	if (d->duk_draw.mat.loc_beg <= d->duk_draw.mat.loc_end &&
		(d->duk_draw.d_he + 32 + 1 - d->duk_draw.d_til) % 32
		&& d->duk_draw.mat.dr_nei >= 0)
	{
		*d->duk_draw.d_he = (t_dest) { d->duk_draw.mat.dr_nei,
			d->duk_draw.mat.loc_beg, d->duk_draw.mat.loc_end};
		if (32 + d->duk_draw.dr_ue == ++d->duk_draw.d_he)
		{
			d->duk_draw.d_he = d->duk_draw.dr_ue;
		}
	}
}

void			draw_scr_init(t_my_doom *d, int *rend_sectr)
{
	d->duk_draw.d_he = d->duk_draw.dr_ue;
	d->duk_draw.tini.x = 0;
	d->duk_draw.d_til = d->duk_draw.dr_ue;
	while (WIDTH > d->duk_draw.tini.x)
	{
		d->duk_draw.t_y[d->duk_draw.tini.x++] = 0;
	}
	d->duk_draw.tini.x = 0;
	while (WIDTH > d->duk_draw.tini.x)
	{
		d->duk_draw.botm_y[d->duk_draw.tini.x++] = HEIGHT - 1;
	}
	d->duk_draw.tini.n = 0;
	while (d->duk_draw.sec_num > d->duk_draw.tini.n)
	{
		rend_sectr[d->duk_draw.tini.n++] = 0;
	}
	d->duk_draw.tini.qu = -1;
	while (++d->duk_draw.tini.qu < 32)
	{
		*d->duk_draw.d_he = (t_dest) { d->dk_user.us_sec, 0, WIDTH - 1 };
	}
	if (++d->duk_draw.d_he == 32 + d->duk_draw.dr_ue)
		d->duk_draw.d_he = d->duk_draw.dr_ue;
}

void			render_room_sec(t_my_doom *d)
{
	d->duk_draw.mat.sect = &d->duk_sec[d->duk_draw.mat.now.sectorno];
	d->duk_draw.tini.s = -1;
	while (d->duk_draw.mat.sect->num_p > ++d->duk_draw.tini.s)
	{
		player_calc_view(d);
		if (d->duk_draw.mat.z_2 <= 0 && 0 >= d->duk_draw.mat.z_1)
		{
			continue ;
		}
		wall_intersec(d);
		perspect_trans(d);
		if (d->duk_draw.mat.now.sx1 > d->duk_draw.mat.x2
			|| d->duk_draw.mat.x1 >= d->duk_draw.mat.x2
			|| d->duk_draw.mat.now.sx2 < d->duk_draw.mat.x1)
		{
			continue ;
		}
		d->duk_draw.tini.i_wa++;
		texture_full_wall(d);
		s_neighbor(d);
	}
}

void			draw_screen(t_my_doom *d)
{
	int render_sec[d->duk_draw.sec_num];

	d->duk_draw.tini.i_wa = 0;
	draw_scr_init(d, render_sec);
	while (d->duk_draw.d_he != d->duk_draw.d_til)
	{
		d->duk_draw.mat.now = *d->duk_draw.d_til;
		if (32 + d->duk_draw.dr_ue == ++d->duk_draw.d_til)
		{
			d->duk_draw.d_til = d->duk_draw.dr_ue;
		}
		if (render_sec[d->duk_draw.mat.now.sectorno] & 0x21)
		{
			continue ;
		}
		++render_sec[d->duk_draw.mat.now.sectorno];
		render_room_sec(d);
		++render_sec[d->duk_draw.mat.now.sectorno];
	}
	if (d->duk_draw.tini.i_wa == 0)
	{
		draw_pre_frame(d);
	}
	else
		cur_frame(d);
}
