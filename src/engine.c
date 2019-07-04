/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:04:06 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:04:10 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		help_fly(t_my_doom *my, float nex)
{
	{
		if (nex > my->duk_sec[my->dk_user.us_sec].ceil)
			my->dk_user.us_sp.z = 0;
		else
		{
			my->dk_user.where.z += my->dk_user.us_sp.z;
			my->duk_gm.m_ng = 1;
			my->dk_user.us_sp.z -= 0.5;
		}
	}
}

void		fly_phys_doom(t_my_doom *my, float nex)
{
	if (my->dk_user.us_sp.z > 0)
		help_fly(my, nex);
	else if (my->dk_user.us_sp.z < 0)
	{
		if (nex < my->duk_sec[my->dk_user.us_sec].floor + my->duk_gm.n_eyht)
		{
			my->dk_user.where.z = my->duk_sec[my->dk_user.us_sec].floor
					+ my->duk_gm.n_eyht;
			my->dk_user.us_sp.z = 0;
		}
		else
		{
			my->dk_user.where.z += my->dk_user.us_sp.z;
			my->duk_gm.m_ng = 1;
			my->dk_user.us_sp.z += 0.5;
		}
	}
}

void		help_ver_col_doom(t_my_doom *my)
{
	{
		my->dk_user.where.z = my->duk_sec[my->dk_user.us_sec].floor
				+ my->duk_gm.n_eyht;
		my->dk_user.us_sp.z = 0;
		my->duk_gm.f_ng = 0;
		my->duk_gm.gr_d = 1;
	}
}

void		vert_col_doom(t_my_doom *my)
{
	float nex;

	if (my->duk_gm.f_ng)
	{
		my->dk_user.us_sp.z -= 0.05f;
		nex = my->dk_user.where.z + my->dk_user.us_sp.z;
		if (my->dk_user.us_sp.z < 0 &&
		nex < my->duk_sec[my->dk_user.us_sec].floor + my->duk_gm.n_eyht)
			help_ver_col_doom(my);
		else if (my->dk_user.us_sp.z > 0 && nex >
		my->duk_sec[my->dk_user.us_sec].ceil)
		{
			my->dk_user.us_sp.z = 0;
			my->duk_gm.f_ng = 1;
		}
		if (my->duk_gm.f_ng)
		{
			my->dk_user.where.z += my->dk_user.us_sp.z;
			my->duk_gm.m_ng = 1;
		}
	}
}
