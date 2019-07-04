/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:25:14 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:25:17 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	find_vtex(char **rd, t_lin2 *vtex)
{
	int *arr;
	int y;
	int v_arr;
	int nbr;

	v_arr = 0;
	nbr = 0;
	y = 0;
	while (rd[y])
	{
		if (0 == ft_strncmp("vertex ", rd[y], 7))
		{
			nbr = 3;
			arr = ft_intsplit(rd[y], ' ');
			while (1 + arr[0] > nbr)
			{
				vtex[v_arr].y = arr[2];
				vtex[v_arr].x = arr[nbr];
				v_arr++;
				nbr++;
			}
			ft_free_int(&arr);
		}
		y++;
	}
}

void	find_vtex_sec(t_my_doom *dat, t_lin2 *vtex, int *arr, int sect)
{
	int v_arr;
	int i;
	int l;

	l = (arr[0] - 3) / 2;
	dat->duk_sec[sect].ceil = arr[3];
	dat->duk_sec[sect].floor = arr[2];
	dat->duk_sec[sect].d_top = (t_lin2 *)malloc(sizeof(t_lin2) * (l + 1));
	dat->duk_sec[sect].num_p = l;
	i = 4;
	v_arr = 1;
	while (l > v_arr)
	{
		dat->duk_sec[sect].d_top[v_arr].x = vtex[arr[i]].x;
		dat->duk_sec[sect].d_top[v_arr].y = vtex[arr[i]].y;
		v_arr++;
		i++;
	}
	dat->duk_sec[sect].d_top[v_arr].x = vtex[arr[i]].x;
	dat->duk_sec[sect].d_top[0].x = vtex[arr[i]].x;
	dat->duk_sec[sect].d_top[v_arr].y = vtex[arr[i]].y;
	dat->duk_sec[sect].d_top[0].y = vtex[arr[i]].y;
}

void	find_sec_2(t_my_doom *dat, int *arr, int sect)
{
	int i;
	int l;
	int v_arr;

	l = (arr[0] - 3) / 2;
	dat->duk_sec[sect].n_bor =
		(signed char *)malloc(sizeof(signed char) * (l + 1));
	i = 4 + l;
	v_arr = 0;
	while (l > v_arr)
	{
		dat->duk_sec[sect].n_bor[v_arr] = (signed char)arr[i];
		v_arr++;
		i++;
	}
	dat->duk_sec[sect].ce_go = dat->duk_sec[sect].ceil;
	dat->duk_sec[sect].door = 0;
	dat->duk_sec[sect].lift = 0;
	dat->duk_sec[sect].end = 0;
	dat->duk_sec[sect].num_t = 0;
	dat->duk_sec[sect].light = 0;
	dat->duk_sec[sect].fl_go = dat->duk_sec[sect].floor;
}

void	find_plr(t_my_doom *dat, int *arr)
{
	dat->dk_user.where.y = arr[3];
	dat->dk_user.us_sec = arr[5];
	dat->dk_user.where.x = arr[2];
	dat->dk_user.invspr.i_we_tp = 1;
	dat->dk_user.invspr.ammo = 300;
	dat->dk_user.invspr.jackpack = 0;
	dat->dk_user.where.z = dat->duk_sec[dat->dk_user.us_sec].floor + 6;
	dat->dk_user.us_ang = arr[4];
	dat->dk_user.invspr.hp = 100;
	dat->dk_user.invspr.armor = 20;
}

void	pars_data_main(t_my_doom *dat, t_sour *m, char **rd)
{
	int		i;
	int		sect;
	t_lin2	vtex[400];
	int		*arr;

	sect = 0;
	i = -1;
	find_vtex(rd, (t_lin2 *)vtex);
	dat->duk_sec = (t_room *)malloc(sizeof(t_room) * m->sec_sou);
	while (rd[++i])
	{
		if (!(ft_strncmp("sector ", rd[i], 7)))
		{
			arr = ft_intsplit(rd[i], ' ');
			find_vtex_sec(dat, (t_lin2 *)vtex, arr, sect);
			find_sec_2(dat, arr, sect++);
			ft_free_int(&arr);
		}
		if (!(ft_strncmp("player ", rd[i], 7)))
		{
			arr = ft_intsplit(rd[i], ' ');
			find_plr(dat, arr);
			ft_free_int(&arr);
		}
	}
}
