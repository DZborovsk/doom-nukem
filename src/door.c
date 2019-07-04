/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:13:11 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:13:13 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		close_door(t_my_doom *main, int i)
{
	float speed_door;

	speed_door = 0.5;
	main->duk_sec[i].ceil = main->duk_sec[i].ceil - speed_door;
	if (main->duk_sec[i].floor >= main->duk_sec[i].ceil)
	{
		main->duk_sec[i].ceil = main->duk_sec[i].floor;
		main->duk_sec[i].door = 2;
		main->duk_gm.p_dor--;
	}
}

static void		open_door(t_my_doom *main, int i)
{
	float speed_door;

	speed_door = 0.5;
	main->duk_sec[i].ceil = speed_door + main->duk_sec[i].ceil;
	if (main->duk_sec[i].ce_go <= main->duk_sec[i].ceil)
	{
		main->duk_sec[i].ceil = main->duk_sec[i].ce_go;
		main->duk_sec[i].door = 1;
		main->duk_gm.p_dor--;
	}
}

void			check_door(t_my_doom *main)
{
	unsigned int i;

	i = 0;
	while (main->duk_draw.sec_num > i)
	{
		if (4 == main->duk_sec[i].door)
		{
			close_door(main, i);
		}
		else if (3 == main->duk_sec[i].door)
		{
			open_door(main, i);
		}
		i++;
	}
}

void			interact_door(t_my_doom *main)
{
	int				s_door;
	unsigned int	y;

	if (main->dk_user.invspr.dr_key == 1)
	{
		y = 0;
		while (main->duk_sec[main->dk_user.us_sec].num_p > y)
		{
			s_door = main->duk_sec[main->dk_user.us_sec].n_bor[y];
			if (0 < main->duk_sec[s_door].door)
			{
				if (1 == main->duk_sec[s_door].door)
				{
					main->duk_sec[s_door].door = 4;
					main->duk_gm.p_dor++;
				}
				else if (2 == main->duk_sec[s_door].door)
				{
					main->duk_sec[s_door].door = 3;
					main->duk_gm.p_dor++;
				}
			}
			y++;
		}
	}
}
