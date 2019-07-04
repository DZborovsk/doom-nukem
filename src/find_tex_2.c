/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tex_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:25:38 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:25:40 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	find_finish(t_my_doom *dat, char **rd, int i)
{
	int *arr;

	if (!(ft_strncmp("end ", rd[i], 4)))
	{
		arr = ft_intsplit(rd[i], ' ');
		dat->duk_sec[arr[2]].end = 1;
		ft_free_int(&arr);
	}
}

void	find_tex(t_my_doom *dat, char **rd, int i)
{
	int *arr;

	if (ft_strncmp("texture_sector ", rd[i], 15) == 0)
	{
		arr = ft_intsplit(rd[i], ' ');
		dat->duk_sec[arr[2]].num_t = arr[3];
		ft_free_int(&arr);
	}
}

void	find_door(t_my_doom *dat, char **rd, int i)
{
	int *arr;

	if (ft_strncmp("door_sector ", rd[i], 12) == 0)
	{
		arr = ft_intsplit(rd[i], ' ');
		dat->duk_sec[arr[2]].door = 2;
		dat->duk_sec[arr[2]].ceil = dat->duk_sec[arr[2]].floor;
		ft_free_int(&arr);
	}
}

void	find_lift(t_my_doom *dat, char **rd, int i)
{
	int *arr;

	if (ft_strncmp("lift ", rd[i], 5) == 0)
	{
		arr = ft_intsplit(rd[i], ' ');
		dat->duk_sec[arr[2]].lift = 1;
		ft_free_int(&arr);
	}
}

void	save_coords(t_my_doom *dat, t_sour *m, char **rd)
{
	int arr[400];
	int i;
	int z;

	dat->duk_draw.sec_num = (size_t)m->sec_sou;
	z = 0;
	while ((int)dat->duk_draw.sec_num > z)
	{
		arr[z] = 0;
		z++;
	}
	sprite_loading(dat);
	i = 0;
	while (rd[i])
	{
		find_finish(dat, rd, i);
		find_tex(dat, rd, i);
		find_door(dat, rd, i);
		find_lift(dat, rd, i);
		doom_parse_search_item(dat, rd, i, (int*)arr);
		doom_parse_search_enemy(dat, rd, i, (int*)arr);
		doom_parse_search_key(dat, rd, i, (int*)arr);
		i++;
	}
}
