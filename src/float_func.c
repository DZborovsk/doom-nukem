/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:17:32 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:18:06 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

float	f_min(float x, float y)
{
	if (x < y)
	{
		return (x);
	}
	return (y);
}

float	f_max(float x, float y)
{
	if (x < y)
	{
		return (y);
	}
	return (x);
}

float	clamp_float(float a, float m1, float m2)
{
	float res_max;
	float res;

	res_max = f_max(a, m1);
	res = f_min(res_max, m2);
	res_max = 0;
	return (res);
}

float	vxs_float(float i, float j, float m, float z)
{
	float res;

	res = (i) * (z) - (m) * (j);
	return (res);
}

float	point_side_fl(t_lin3 cr1, float y0, float x1, float y1)
{
	float res;

	res = vxs_float((x1) - (cr1.z), (y1) - (y0),
			(cr1.x) - (cr1.z), (cr1.y) - (y0));
	return (res);
}
