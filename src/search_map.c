/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:14:36 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:14:38 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	doom_parse_search_item(t_my_doom *my,
		char **read, int y, int *sprite)
{
	int *tab;
	int res_strn;
	int max_sprite;

	max_sprite = 5;
	res_strn = ft_strncmp("ammunition ", read[y], 11);
	if (res_strn == 0)
	{
		tab = ft_intsplit(read[y], ' ');
		if (sprite[tab[5]] < 5)
		{
			if (tab[2] == 1)
				my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]].id_sp_d = 4;
			else if (tab[2] == 2)
				my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]].id_sp_d = 3;
			else if (tab[2] == 3)
				my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]].id_sp_d = 5;
			my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]].position.x = tab[3];
			my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]].position.y = tab[4];
			sprite[tab[5]]++;
		}
		ft_free_int(&tab);
	}
}

void	doom_parse_search_enemy(t_my_doom *my, char **read, int y,
	int *sprite)
{
	int *tab;
	int res_strn;
	int max_sprite;

	max_sprite = 5;
	res_strn = ft_strncmp("enemy ", read[y], 6);
	if (res_strn == 0)
	{
		tab = ft_intsplit(read[y], ' ');
		if (sprite[tab[4]] < max_sprite)
		{
			my->duk_sec[tab[4]].sp_thi[sprite[tab[4]]]
			.id_sp_d = 6;
			my->duk_sec[tab[4]].sp_thi[sprite[tab[4]]]
			.position.x = tab[2];
			my->duk_sec[tab[4]].sp_thi[sprite[tab[4]]]
			.position.y = tab[3];
			sprite[tab[4]]++;
		}
		ft_free_int(&tab);
	}
}

void	doom_parse_search_key(t_my_doom *my, char **read, int y,
	int *sprite)
{
	int *tab;
	int max_sprite;
	int res_strn;

	max_sprite = 5;
	res_strn = ft_strncmp("key ", read[y], 4);
	if (res_strn == 0)
	{
		tab = ft_intsplit(read[y], ' ');
		if (sprite[tab[5]] < max_sprite)
		{
			if (tab[2] == 1)
				my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]]
			.id_sp_d = 1;
			if (tab[2] == 3)
				my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]]
			.id_sp_d = 2;
			my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]]
			.position.x = tab[3];
			my->duk_sec[tab[5]].sp_thi[sprite[tab[5]]]
			.position.y = tab[4];
			sprite[tab[5]]++;
		}
		ft_free_int(&tab);
	}
}
