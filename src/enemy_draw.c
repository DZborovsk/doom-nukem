/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:09:46 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:09:48 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_multi_imp(t_my_doom *main, float an_cos)
{
	if (main->duk_draw.mat.sect->sp_thi[main->duk_draw.
	dr_sp.n_spr].position.y >= main->dk_user.where.y)
	{
		if (an_cos >= 0.7 && 1 >= an_cos)
		{
			draw_item_sprite(main, 3);
		}
		else if (0.7 > an_cos && an_cos >= 0)
			draw_item_sprite(main, 4);
		else if (-0.7 <= an_cos && 0 > an_cos)
			draw_item_sprite(main, 5);
		else if (an_cos >= -1 && an_cos < -0.7)
			draw_item_sprite(main, 6);
	}
	else
	{
		if (an_cos >= 0.7 && 1 >= an_cos)
			draw_item_sprite(main, 10);
		else if (0.7 > an_cos && 0 <= an_cos)
			draw_item_sprite(main, 9);
		else if (an_cos < 0 && an_cos >= -0.7)
			draw_item_sprite(main, 8);
		else if (an_cos >= -1 && -0.7 > an_cos)
			draw_item_sprite(main, 7);
	}
}

void	draw_imp_stuff(t_my_doom *main)
{
	float	an_cos;
	float	ax;
	float	bx;
	float	by;
	float	ay;

	ax = main->dk_user.where.x
		- main->duk_draw.mat.sect->sp_thi[main->
		duk_draw.dr_sp.n_spr].position.x;
	ay = main->dk_user.where.y
		- main->duk_draw.mat.sect->sp_thi[main->
		duk_draw.dr_sp.n_spr].position.y;
	bx = 2 + main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.x;
	by = main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.y;
	an_cos = ((bx * ax) + (by * ay))
		/ (sqrt((ax * ax) + (ay * ay))
			* sqrt(bx * bx + by * by));
	draw_multi_imp(main, an_cos);
	if (main->duk_draw.mat.en_dr > 600 && 0 < main->dk_user.invspr.i_we_mh
		&& main->duk_draw.mat.dr_bg < 600)
		help_drav_imp(main);
}
