/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:25:34 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:25:35 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	mouse_2(t_my_doom *m_dat, SDL_Event event, t_sour *data)
{
	(void)m_dat;
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if (event.type == SDL_MOUSEBUTTONDOWN && 1
		== m_dat->menu.m_n && m_dat->menu.flag == 0)
		{
			m_dat->menu.flag = 1;
		}
		else if (0 == m_dat->menu.m_n && m_dat->menu.flag
		== 0 && SDL_MOUSEBUTTONDOWN == event.type)
		{
			go_doom(m_dat, data);
		}
		else if (SDL_MOUSEBUTTONDOWN == event.type)
		{
			m_dat->run_gn = 1;
		}
	}
}

void	mouse_main(t_my_doom *dat, SDL_Event event)
{
	if (SDL_BUTTON_LEFT == event.button.button)
	{
		if (dat->dk_user.invspr.wea_ph == 1
			&& 1 <= dat->dk_user.invspr.ammo
			&& dat->dk_user.invspr.i_we_tp == 1)
		{
			dat->dk_user.invspr.ammo--;
			dat->dk_user.invspr.wea_ph++;
			dat->dk_user.invspr.i_we_mh = 1;
			Mix_PlayChannel(-1, dat->guns[0], 0);
		}
		else if (dat->dk_user.invspr.wea_ph == 1
				&& 5 <= dat->dk_user.invspr.ammo
				&& 2 == dat->dk_user.invspr.i_we_tp)
		{
			dat->dk_user.invspr.wea_ph++;
			dat->dk_user.invspr.ammo = dat->dk_user.invspr.ammo - 5;
			dat->dk_user.invspr.i_we_mh = 5;
			Mix_PlayChannel(-1, dat->guns[1], 0);
		}
	}
}
