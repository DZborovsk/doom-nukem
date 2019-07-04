/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:22:11 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:22:33 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void			make_color(t_my_doom *d, int x, int y, int texture)
{
	int c;

	if (52 > d->duk_draw.mat.v && d->duk_draw.mat.u < 48)
	{
		c = d->duk_draw.dr_car[texture][d->duk_draw.mat.u][d->duk_draw.mat.v];
		if (c != 0x000000)
		{
			if (d->duk_sec[d->duk_draw.mat.now.sectorno].light == 0)
			{
				d->duk_draw.dr_img[y][x] =
					pixel_bright(c, 0.015 * d->duk_draw.mat.z);
			}
			else
			{
				d->duk_draw.dr_img[y][x] = c;
			}
		}
	}
}

static float		interpolate(t_my_doom *d, float cmp_tex,
	float sample_rat)
{
	if (48 <= d->duk_draw.mat.u)
	{
		cmp_tex = 0;
		d->duk_draw.mat.u = 0;
	}
	else
	{
		cmp_tex = cmp_tex + sample_rat;
		d->duk_draw.mat.u = (int)cmp_tex;
	}
	return (cmp_tex);
}

void				v_line_card(t_my_doom *d, int x, int texture)
{
	int		y2;
	int		y;
	int		y1;
	float	sample_rat;
	float	cmp_tex;

	y2 = d->duk_draw.dr_sp.y2;
	y1 = d->duk_draw.dr_sp.y1;
	if (y1 < y2)
	{
		sample_rat = (float)48 / (float)(abs(y2 - y1));
		if (sample_rat < 0.005)
			sample_rat = 0.005;
		cmp_tex = 0;
		y = y1;
		while (y2 >= y)
		{
			cmp_tex = interpolate(d, cmp_tex, sample_rat);
			if (y >= y1)
				if (0 < y && y < HEIGHT)
					make_color(d, x, y, texture);
			y++;
		}
	}
}
