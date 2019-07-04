/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lift.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:00:10 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:00:13 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	help_check_lift(t_my_doom *main, unsigned int i, float speed)
{
	int down;

	down = 1;
	{
		main->duk_sec[i].floor -= speed;
		if (main->duk_sec[i].floor <= main->duk_sec[i].fl_go)
		{
			main->duk_sec[i].floor = main->duk_sec[i].fl_go;
			main->duk_sec[i].lift = down;
			main->duk_gm.p_lif--;
		}
	}
}

void	motion_lift(t_my_doom *main)
{
	int		lift_check;
	int		up;
	int		down;
	int		falling;

	up = 2;
	down = 1;
	lift_check = 4;
	falling = 3;
	if (main->dk_user.invspr.gr_key == 1)
		if (main->duk_sec[main->dk_user.us_sec].lift > 0)
		{
			if (main->duk_sec[main->dk_user.us_sec].lift == down)
			{
				main->duk_sec[main->dk_user.us_sec].lift = lift_check;
				main->duk_gm.p_lif++;
			}
			else if (main->duk_sec[main->dk_user.us_sec].lift == up)
			{
				main->duk_sec[main->dk_user.us_sec].lift = falling;
				main->duk_gm.p_lif++;
			}
		}
}
