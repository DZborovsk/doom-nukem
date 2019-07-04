/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:24:28 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:24:34 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	find_end_sprt(t_my_doom *main, float d)
{
	float vec1_x_l;
	float vec2_y_l;
	float vec1_y_l;
	float vec2_x_l;

	vec1_x_l = (main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.x
		- main->dk_user.where.x) / d;
	vec1_y_l = (main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.y
		- main->dk_user.where.y) / d;
	vec2_y_l = vec1_x_l;
	vec2_x_l = -vec1_y_l;
	main->duk_draw.mat.v1y = (main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.y
		- main->dk_user.where.y);
	main->duk_draw.mat.v1x = (main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.x
		- main->dk_user.where.x);
	main->duk_draw.mat.v2x = (vec2_x_l * 1)
		+ main->duk_draw.mat.sect->sp_thi[main->
		duk_draw.dr_sp.n_spr].position.x - main->dk_user.where.x;
	main->duk_draw.mat.v2y = (vec2_y_l * 1)
		+ main->duk_draw.mat.sect->sp_thi[main->
		duk_draw.dr_sp.n_spr].position.y - main->dk_user.where.y;
}

void	find_visual_sprt(t_my_doom *main, float d)
{
	main->duk_draw.mat.ce_y = main->duk_draw.mat.sect->sp_thi
			[main->duk_draw.dr_sp.n_spr].c_sp_d - main->dk_user.where.z;
	main->duk_draw.mat.flo_y = main->duk_draw.mat.sect->sp_thi
			[main->duk_draw.dr_sp.n_spr].f_sp_d - main->dk_user.where.z;
	main->duk_draw.mat.a1_y = (HEIGHT / 2) - (int)(yaw(main,
			main->duk_draw.mat.ce_y, main->duk_draw.mat.z_1)
		* main->duk_draw.mat.scl_y1);
	main->duk_draw.mat.b1_y = (HEIGHT / 2) - (int)(yaw(main,
			main->duk_draw.mat.flo_y, main->duk_draw.mat.z_1)
		* main->duk_draw.mat.scl_y1);
	main->duk_draw.mat.y2_a = (HEIGHT / 2) - (int)(yaw(main,
			main->duk_draw.mat.ce_y, main->duk_draw.mat.z_2)
		* main->duk_draw.mat.scl_y2);
	main->duk_draw.mat.b2_y = (HEIGHT / 2) - (int)(yaw(main,
			main->duk_draw.mat.flo_y, main->duk_draw.mat.z_2)
		* main->duk_draw.mat.scl_y2);
	main->duk_draw.mat.dr_bg = main->duk_draw.mat.x1;
	main->duk_draw.mat.en_dr = (2000 / d) + main->duk_draw.mat.dr_bg;
	if (main->duk_draw.mat.en_dr < 0)
	{
		main->duk_draw.mat.en_dr = 0;
	}
}

void	form_of_transformn(t_my_doom *main)
{
	main->duk_draw.mat.c_p = main->dk_user.cos_an;
	main->duk_draw.mat.s_p = main->dk_user.sin_an;
	main->duk_draw.mat.t_1 = (main->duk_draw.mat.v1x * main->duk_draw.
			mat.s_p) - (main->duk_draw.mat.v1y * main->duk_draw.mat.c_p);
	main->duk_draw.mat.z_1 = (main->duk_draw.mat.v1x * main->duk_draw.
			mat.c_p) + (main->duk_draw.mat.v1y * main->duk_draw.mat.s_p);
	main->duk_draw.mat.t_2 = (main->duk_draw.mat.v2x * main->duk_draw.
			mat.s_p) - (main->duk_draw.mat.v2y * main->duk_draw.mat.c_p);
	main->duk_draw.mat.z_2 = (main->duk_draw.mat.v2x * main->duk_draw.
			mat.c_p) + (main->duk_draw.mat.v2y * main->duk_draw.mat.s_p);
}

int		calc_view_sprt(t_my_doom *main)
{
	int		r;
	float	aby;
	float	abx;

	abx = (main->dk_user.where.x
		- main->duk_draw.mat.sect->sp_thi[main->
		duk_draw.dr_sp.n_spr].position.x);
	aby = (main->dk_user.where.y
		- main->duk_draw.mat.sect->sp_thi[main->
		duk_draw.dr_sp.n_spr].position.y);
	main->duk_draw.dr_sp.d_len = (float)sqrt((abx * abx) + (aby * aby));
	r = calc_sprt_inter(main);
	if (r != -1)
	{
		return (r);
	}
	find_end_sprt(main, main->duk_draw.dr_sp.d_len);
	form_of_transformn(main);
	if (main->duk_draw.mat.z_2 <= 0 && main->duk_draw.mat.z_1 <= 0)
	{
		return (-1);
	}
	perspect_trans(main);
	find_visual_sprt(main, main->duk_draw.dr_sp.d_len);
	return (10);
}
