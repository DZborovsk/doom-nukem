/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:20:46 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:21:46 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_lin2		set_unlim_point(t_lin2 point, int flag_1)
{
	t_lin2		un;
	int			max;

	max = 999999;
	if (flag_1 == 1)
	{
		un.x = point.x;
		un.y = max;
	}
	else if (flag_1 == 2)
	{
		un.x = max;
		un.y = max;
	}
	else
	{
		un.x = max;
		un.y = point.y;
	}
	return (un);
}

int			p_inside_doom(t_lin2 *ver, size_t numb, t_lin2 point, int flag_1)
{
	t_lin2		un;
	int			dur;

	ver->m_in_j = 0;
	ver->m_in_i = 0;
	un = set_unlim_point(point, flag_1);
	if (3 > numb)
		return (0);
	while (1)
	{
		dur = (ver->m_in_i + 1) % numb;
		if (main_math(ver[ver->m_in_i], ver[dur], point, un))
		{
			if (0 == vis_orient_doom(ver[ver->m_in_i], point, ver[dur]))
				return (change_vec_doom(ver[ver->m_in_i], point, ver[dur]));
			ver->m_in_j++;
		}
		ver->m_in_i = dur;
		if (0 == ver->m_in_i)
			break ;
	}
	if (1 == ver->m_in_j % 2)
		return (1);
	return (0);
}

int			help_j(t_my_doom *my, int j, size_t i)
{
	if (j > 0)
		if (my->dk_user.us_sec == i)
			return (1);
	return (0);
}

int			p_doom_map(t_my_doom *my)
{
	int		j;
	t_lin2	point;
	int		res;

	point.x = my->dk_user.where.x;
	point.y = my->dk_user.where.y;
	my->m_dk_i = 0;
	while (my->m_dk_i < my->duk_draw.sec_num)
	{
		j = 0;
		if (p_inside_doom(my->duk_sec[my->m_dk_i].d_top,
				my->duk_sec[my->m_dk_i].num_p, point, 1) == 1)
			j++;
		if (p_inside_doom(my->duk_sec[my->m_dk_i].d_top,
				my->duk_sec[my->m_dk_i].num_p, point, 2) == 1)
			j++;
		if (p_inside_doom(my->duk_sec[my->m_dk_i].d_top,
				my->duk_sec[my->m_dk_i].num_p, point, 3) == 1)
			j++;
		res = help_j(my, j, my->m_dk_i);
		if (res == 1)
			return (1);
		my->m_dk_i++;
	}
	return (0);
}
