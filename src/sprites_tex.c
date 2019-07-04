/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:18:31 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:18:49 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	item_inter_2(t_my_doom *my, int r)
{
	if (4 == r)
	{
		my->dk_user.invspr.ammo = 15 + my->dk_user.invspr.ammo;
		if (my->dk_user.invspr.ammo > 300)
		{
			my->dk_user.invspr.ammo = 300;
		}
	}
	else if (5 == r)
	{
		my->dk_user.invspr.armor = my->dk_user.invspr.armor + 20;
		if (500 < my->dk_user.invspr.armor)
		{
			my->dk_user.invspr.armor = 500;
		}
	}
	else if (6 == r)
	{
		my->duk_draw.mat.sect->sp_thi[my->duk_draw.dr_sp.n_spr].id_sp_d = 6;
	}
}

void	item_inter_1(t_my_doom *my, int r)
{
	if (1 == r)
	{
		my->dk_user.invspr.dr_key = 1;
	}
	else if (2 == r)
	{
		my->dk_user.invspr.gr_key = 1;
	}
	else if (3 == r)
	{
		my->dk_user.invspr.hp = my->dk_user.invspr.hp + 10;
		if (my->dk_user.invspr.hp > 100)
		{
			my->dk_user.invspr.hp = 100;
		}
	}
	item_inter_2(my, r);
}

void	draw_sector_sprite(t_my_doom *my)
{
	int r;

	my->duk_draw.dr_sp.n_spr = 0;
	while (5 > my->duk_draw.dr_sp.n_spr)
	{
		if (my->duk_draw.mat.sect->sp_thi
		[my->duk_draw.dr_sp.n_spr].id_sp_d >= 0)
		{
			r = calc_view_sprt(my);
			if (10 == r)
			{
				tex_sprt(my);
			}
			else if (r >= 0)
			{
				item_inter_1(my, r);
			}
		}
		my->duk_draw.dr_sp.n_spr++;
	}
}

void	draw_spritekit(t_my_doom *my)
{
	int sector_rend[my->duk_draw.sec_num];

	draw_scr_init(my, sector_rend);
	while (my->duk_draw.d_he != my->duk_draw.d_til)
	{
		my->duk_draw.mat.now = *my->duk_draw.d_til;
		if (++my->duk_draw.d_til == my->duk_draw.dr_ue + 32)
		{
			my->duk_draw.d_til = my->duk_draw.dr_ue;
		}
		if (sector_rend[my->duk_draw.mat.now.sectorno] & 0x21)
		{
			continue ;
		}
		++sector_rend[my->duk_draw.mat.now.sectorno];
		my->duk_draw.mat.sect = &my->duk_sec[my->duk_draw.mat.now.sectorno];
		draw_textures_wall(my);
		draw_sector_sprite(my);
		++sector_rend[my->duk_draw.mat.now.sectorno];
	}
}
