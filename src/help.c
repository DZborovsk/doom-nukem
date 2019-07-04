/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:20:15 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:20:17 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ex_help(void)
{
	ft_putstr("Choose the LVL!");
	exit(1);
}

int		doom_ev_help(t_my_doom *my, t_sour *data, SDL_Event event)
{
	if (((event.key.keysym.sym == SDLK_RETURN) ||
	(my->run_gn)) && my->menu.m_n == 1)
		my->menu.flag = 1;
	else if (((event.key.keysym.sym == SDLK_RETURN) ||
	(my->run_gn)) && my->menu.m_n == 2 && my->menu.flag != 1)
		return (1);
	else if (((event.key.keysym.sym == SDLK_RETURN) ||
	(my->run_gn)) && my->menu.m_n == 0 && my->menu.flag == 1)
	{
		if ((data->name = "./media/maps/1_level.map") &&
		go_doom(my, data) == 1)
			return (1);
	}
	else if (((event.key.keysym.sym == SDLK_RETURN) ||
	(my->run_gn)) && my->menu.m_n == 2 && my->menu.flag == 1)
	{
		if ((data->name = "./media/maps/2_level.map") &&
			go_doom(my, data) == 1)
			return (1);
	}
	if (((event.key.keysym.sym == SDLK_RETURN) ||
	(my->run_gn)) && my->menu.m_n == 1 && my->menu.flag != 1)
		ex_help();
	return (0);
}

void	mouse_selector(t_my_doom *my, SDL_Event event, t_sour *data)
{
	SDL_GetMouseState(&my->duk_gm.x_m, &my->duk_gm.y_m);
	mouse_2(my, event, data);
	if (my->duk_gm.x_m > 20 && my->duk_gm.x_m < 270)
		if (my->duk_gm.y_m > 620 && my->duk_gm.y_m < HEIGHT)
		{
			if (my->duk_gm.y_m > 620 && my->duk_gm.y_m < (620 + 50))
				my->menu.m_n = 0;
			if (my->duk_gm.y_m > (620 + 50) && my->duk_gm.y_m < (620 + 100))
				my->menu.m_n = 1;
			if (my->duk_gm.y_m > (620 + 100) && my->duk_gm.y_m < (620 + 150))
				my->menu.m_n = 2;
		}
}
