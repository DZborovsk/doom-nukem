/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:15:03 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:15:27 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	help_sc_cal(t_my_doom *my)
{
	my->duk_draw.mat.v1y = my->duk_draw.mat.v2y;
	my->duk_draw.mat.v1x = my->duk_draw.mat.v2x;
	my->duk_draw.mat.v2y = my->duk_draw.mat.v3y;
	my->duk_draw.mat.v2x = my->duk_draw.mat.v3x;
	my->duk_draw.mat.s_p = my->dk_user.sin_an;
	my->duk_draw.mat.c_p = my->dk_user.cos_an;
	my->duk_draw.mat.t_1 = (my->duk_draw.mat.v1x * my->duk_draw.
			mat.s_p) - (my->duk_draw.mat.v1y * my->duk_draw.mat.c_p);
	my->duk_draw.mat.z_1 = (my->duk_draw.mat.v1x * my->duk_draw.
			mat.c_p) + (my->duk_draw.mat.v1y * my->duk_draw.mat.s_p);
	my->duk_draw.mat.t_2 = (my->duk_draw.mat.v2x * my->duk_draw.
			mat.s_p) - (my->duk_draw.mat.v2y * my->duk_draw.mat.c_p);
	my->duk_draw.mat.z_2 = (my->duk_draw.mat.v2x * my->duk_draw.
			mat.c_p) + (my->duk_draw.mat.v2y * my->duk_draw.mat.s_p);
}
