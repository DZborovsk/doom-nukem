/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:12:02 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:12:04 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	cos_sphe(t_lin2 pos1, double dis, t_lin2 pos3, t_my_doom *main)
{
	double t_0;

	if (dis >= 0)
	{
		main->dis_sqrt = sqrtl(dis);
		t_0 = (-main->b + main->dis_sqrt) / (2 * main->a);
		main->duk_draw.mat.sect->
		sp_thi[main->duk_draw.dr_sp.n_spr].position.x -= t_0;
		if (pos1.y < pos3.y)
			main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.y -= 1;
		else
			main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.y += 1;
	}
}

void	pos_enemy(t_my_doom *main)
{
	double dis;
	t_lin2 dist;
	t_lin2 pos1;
	t_lin2 pos2;
	t_lin2 pos3;

	main->r = 1;
	pos1.x = main->dk_user.where.x;
	pos1.y = main->dk_user.where.y;
	pos2.x = main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.x;
	pos2.y = main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.y;
	pos3.x = main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.x;
	pos3.y = main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].position.y;
	dist.x = pos1.x - pos3.x;
	dist.y = pos1.y - pos3.y;
	main->a = pos2.x * pos2.x + pos2.y * pos2.y;
	main->b = 2 * (pos2.x * dist.x + pos2.y * dist.y);
	main->c = (dist.x * dist.x + dist.y * dist.y) - main->r * main->r;
	dis = main->b * main->b - 4 * main->a * main->c;
	cos_sphe(pos1, dis, pos3, main);
}
