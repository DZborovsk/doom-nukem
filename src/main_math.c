/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:16:23 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:16:48 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		change_vec_doom(t_lin2 z, t_lin2 m, t_lin2 b)
{
	if (f_min(z.y, b.y) <= m.y
		&& f_max(z.x, b.x) >= m.x
		&& f_min(z.x, b.x) <= m.x
		&& f_max(z.y, b.y) >= m.y)
	{
		return (1);
	}
	return (0);
}

int		vis_orient_doom(t_lin2 z, t_lin2 m, t_lin2 b)
{
	int data;

	data = ((b.x - m.x) * (m.y - z.y))
		- ((b.y - m.y) * (m.x - z.x));
	if (0 == data)
	{
		return (0);
	}
	if (0 < data)
	{
		return (1);
	}
	return (2);
}

int		main_math(t_lin2 rt1, t_lin2 wt1, t_lin2 rt2, t_lin2 wt2)
{
	int j3;
	int j4;
	int j1;
	int j2;

	j1 = vis_orient_doom(rt1, wt1, rt2);
	j2 = vis_orient_doom(rt1, wt1, wt2);
	j3 = vis_orient_doom(rt2, wt2, rt1);
	j4 = vis_orient_doom(rt2, wt2, wt1);
	if (j2 != j1
		&& j4 != j3)
	{
		return (1);
	}
	if (change_vec_doom(rt1, rt2, wt1)
		&& 0 == j1)
		return (1);
	if (change_vec_doom(rt1, wt2, wt1)
		&& 0 == j2)
		return (1);
	if (change_vec_doom(rt2, rt1, wt2) && 0 == j3)
		return (1);
	if (change_vec_doom(rt2, wt1, wt2) && 0 == j4)
		return (1);
	return (0);
}
