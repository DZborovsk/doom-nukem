/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:04:50 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:05:55 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			load_weapons2(t_my_doom *main)
{
	int i;
	int id_sprite;

	main->duk_draw.shun = (int***)malloc(sizeof(int **) * 9);
	id_sprite = 0;
	while (id_sprite < 9)
	{
		i = 0;
		main->duk_draw.shun[id_sprite] = (int**)malloc(sizeof(int *) * 178);
		while (i < 178)
		{
			main->duk_draw.shun[id_sprite][i] = (int*)malloc(sizeof(int) * 178);
			++i;
		}
		dw_shotgun(main, id_sprite);
		++id_sprite;
	}
}

void			load_weapons(t_my_doom *main)
{
	int i;
	int id_sprite;

	id_sprite = 0;
	main->duk_draw.blast = (int***)malloc(sizeof(int **) * 6);
	while (id_sprite < 6)
	{
		main->duk_draw.blast[id_sprite] = (int**)malloc(sizeof(int *) * 128);
		i = 0;
		while (i < 128)
		{
			main->duk_draw.blast[id_sprite][i] =
				(int*)malloc(sizeof(int) * 128);
			++i;
		}
		dw_blaster(main, id_sprite);
		++id_sprite;
	}
	load_weapons2(main);
}

void			draw_weapons(t_my_doom *main)
{
	if (main->dk_user.invspr.i_we_tp == 1)
		draw_pistol_an(main);
	if (main->dk_user.invspr.i_we_tp == 2)
		draw_shotgun(main);
}
