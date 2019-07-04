/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:06:13 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:06:26 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_lin2	doom_inter_sect(t_lin3 vect1, t_lin3 vect2, float i, float j)
{
	t_lin2 res;

	res.x = vxs_float(vxs_float(vect1.x, vect1.y,
			vect1.z, vect2.x), (vect1.x) - (vect1.z),
		vxs_float(vect2.y, vect2.z, i, j), (vect2.y) - (i)) /
		vxs_float((vect1.x) - (vect1.z), (vect1.y) -
		(vect2.x), (vect2.y) - (i),
			(vect2.z) - (j));
	res.y = vxs_float(vxs_float(vect1.x, vect1.y, vect1.z,
			vect2.x), (vect1.y) - (vect2.x),
		vxs_float(vect2.y, vect2.z, i, j), (vect2.z) - (j)) /
		vxs_float((vect1.x) - (vect1.z), (vect1.y) - (vect2.x),
				(vect2.y) - (i),
			(vect2.z) - (j));
	return (res);
}
