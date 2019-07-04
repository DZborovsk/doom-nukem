/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:58:10 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:58:12 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static float	interpolate(t_my_doom *my, float cmprsd_txtr,
	float sampl_rat)
{
	cmprsd_txtr = cmprsd_txtr + sampl_rat;
	my->duk_draw.mat.v = (int)cmprsd_txtr;
	if (0 > my->duk_draw.mat.v || my->duk_draw.mat.v >= 128)
	{
		my->duk_draw.mat.v = 0;
		cmprsd_txtr = 0;
	}
	return (cmprsd_txtr);
}

void			rendr_wall(t_my_doom *my)
{
	float	sampl_rat;
	float	cmprsd_txtr;

	fl_ceil_view(my);
	proj_height(my);
	my->duk_draw.mat.dr_bg = f_max(f_max(my->duk_draw.
			mat.x1, my->duk_draw.mat.now.sx1), my->duk_draw.mat.loc_beg);
	my->duk_draw.mat.en_dr = f_min(f_min(my->duk_draw.
			mat.x2, my->duk_draw.mat.now.sx2), my->duk_draw.mat.loc_end);
	sampl_rat = (float)128 / (float)(abs(my->duk_draw.mat.edg2 -
			my->duk_draw.mat.edg1));
	if (sampl_rat < 0.005)
		sampl_rat = 0.005;
	cmprsd_txtr = 0;
	my->duk_draw.mat.x = my->duk_draw.mat.edg1;
	while (++my->duk_draw.mat.x <= my->duk_draw.mat.en_dr)
	{
		cmprsd_txtr = interpolate(my, cmprsd_txtr, sampl_rat);
		if ((my->duk_draw.mat.dr_bg - 1) < my->duk_draw.mat.x)
		{
			draw_ceil_floor(my);
			draw_walls_pic(my);
		}
	}
}

int				rendr_wall_seg(t_my_doom *my)
{
	if (2 > my->duk_draw.mat.len_f)
		return (-1);
	my->duk_draw.mat.len = 2 + my->duk_draw.mat.len;
	my->duk_draw.mat.v3x = (my->duk_draw.mat.st_vx) +
			(my->duk_draw.mat.en_vx - my->duk_draw.mat.st_vx)
		* (my->duk_draw.mat.len / my->duk_draw.mat.len_f);
	my->duk_draw.mat.v3y = (my->duk_draw.mat.st_vy) +
			(my->duk_draw.mat.en_vy - my->duk_draw.mat.st_vy)
		* (my->duk_draw.mat.len / my->duk_draw.mat.len_f);
	help_sc_cal(my);
	wall_intersec(my);
	perspect_trans(my);
	if (my->duk_draw.mat.x2 < my->duk_draw.mat.now.sx1 || my->
	duk_draw.mat.now.sx2 < my->duk_draw.mat.x1 || my->duk_draw.mat.
	x1 >= my->duk_draw.mat.x2)
		return (0);
	my->duk_draw.mat.edg2 = my->duk_draw.mat.x2;
	my->duk_draw.mat.edg1 = my->duk_draw.mat.x1;
	rendr_wall(my);
	return (1);
}

void			calc_wall_len(t_my_doom *my)
{
	int b;
	int a;

	a = fabs(my->duk_draw.mat.en_vx - my->duk_draw.mat.st_vx);
	b = fabs(my->duk_draw.mat.en_vy - my->duk_draw.mat.st_vy);
	my->duk_draw.mat.len_f = sqrt((a * a) + (b * b));
	my->duk_draw.mat.len = 0;
	if (my->duk_draw.mat.len_f < 2)
	{
		my->duk_draw.mat.edg2 = my->duk_draw.mat.x2;
		my->duk_draw.mat.edg1 = my->duk_draw.mat.x1;
		rendr_wall(my);
	}
}

void			texture_full_wall(t_my_doom *my)
{
	int seg_wall;

	my->duk_draw.mat.loc_beg = f_max(my->
			duk_draw.mat.x1, my->duk_draw.mat.now.sx1);
	my->duk_draw.mat.loc_end = f_min(my->
			duk_draw.mat.x2, my->duk_draw.mat.now.sx2);
	my->duk_draw.mat.st_vy = my->duk_draw.mat.v1y;
	my->duk_draw.mat.st_vx = my->duk_draw.mat.v1x;
	my->duk_draw.mat.en_vy = my->duk_draw.mat.v2y;
	my->duk_draw.mat.en_vx = my->duk_draw.mat.v2x;
	calc_wall_len(my);
	my->duk_draw.mat.v2y = my->duk_draw.mat.v1y;
	my->duk_draw.mat.v2x = my->duk_draw.mat.v1x;
	while (my->duk_draw.mat.len_f > my->duk_draw.mat.len)
	{
		seg_wall = rendr_wall_seg(my);
		if (seg_wall == -1)
		{
			break ;
		}
		else if (seg_wall == 0)
		{
			continue ;
		}
	}
}
