/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:19:36 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:19:38 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

float		calc_tex_pxl(t_my_doom *main, float cmprsd_txtr,
	float sampl_rat)
{
	if (128 <= main->duk_draw.mat.u)
	{
		cmprsd_txtr = 0;
		main->duk_draw.mat.u = 0;
	}
	else
	{
		cmprsd_txtr = sampl_rat + cmprsd_txtr;
		main->duk_draw.mat.u = (int)cmprsd_txtr;
	}
	return (cmprsd_txtr);
}

void		vline_tex(t_my_doom *m, t_post3 b, int texture)
{
	int		y2;
	int		y1;
	int		y;
	float	t;
	float	cmprsd_txtr;

	y2 = b.z;
	y1 = b.y;
	if (y1 < y2)
	{
		t = m->f / (float)(abs(m->duk_draw.mat.y_a - m->duk_draw.mat.y_b));
		if (t < 0.005)
			t = 0.005;
		m->duk_draw.mat.u = 0;
		cmprsd_txtr = 0;
		y = (int)m->duk_draw.mat.y_a - 1;
		if (y < -10000)
			y = -10000;
		while (++y <= y2)
		{
			cmprsd_txtr = calc_tex_pxl(m, cmprsd_txtr, t);
			if (y1 <= y)
				set_pxl_col(m, texture, b.x, y);
		}
	}
}

void		light_pixel_vl(t_my_doom *main,
	t_post3 b, t_post3 c, int y)
{
	if (main->duk_sec[main->duk_draw.mat.now.sectorno].light == 0)
	{
		if (main->duk_draw.mat.cl_fl == 1)
		{
			main->duk_draw.dr_img[y][b.x] = pixel_bright(c.y,
				-1 * ft_map(y, b.y, ft_map_help(HEIGHT, -1, 0)));
		}
		else
		{
			main->duk_draw.dr_img[y][b.x] = pixel_bright(c.y,
				ft_map(y, 0, ft_map_help(b.z, 0, 1)));
		}
	}
	else
	{
		main->duk_draw.dr_img[y][b.x] = c.y;
	}
}

void		vline(t_my_doom *main, t_post3 b, t_post3 c)
{
	int y;

	b.y = clamp_float(b.y, 0, HEIGHT - 1);
	b.z = clamp_float(b.z, 0, HEIGHT - 1);
	if (b.z == b.y)
	{
		main->duk_draw.dr_img[b.y][b.x] = c.y;
	}
	else if (b.y < b.z)
	{
		y = b.y + 1;
		main->duk_draw.dr_img[b.y][b.x] = c.x;
		while (b.z > y)
		{
			light_pixel_vl(main, b, c, y);
			y++;
		}
		main->duk_draw.dr_img[b.z][b.x] = c.z;
	}
}
