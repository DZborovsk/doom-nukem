/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:17:54 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:17:56 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_post3		set_point(int r, int g, int b)
{
	t_post3 result;

	result.x = r;
	result.y = g;
	result.z = b;
	return (result);
}

t_lin3		ft_map_help(float doom_end,
		float doom_start_map, float doom_end_map)
{
	t_lin3 result;

	result.x = doom_end;
	result.y = doom_start_map;
	result.z = doom_end_map;
	return (result);
}

float		ft_map(float num, float sr_start, t_lin3 fun_doom)
{
	float map_end;
	float doom_start_map;
	float doom_end_map;
	float res;

	map_end = fun_doom.x;
	doom_start_map = fun_doom.y;
	doom_end_map = fun_doom.z;
	res = ((num - sr_start) * ((doom_end_map - doom_start_map)
			/ (map_end - sr_start)) + doom_start_map);
	return (res);
}

int			pixel_bright(int pixel_color, float smog)
{
	SDL_Color	color;
	float		max_smog;

	max_smog = 0.9;
	if (smog > max_smog)
		smog = max_smog;
	color.r = ((pixel_color >> 16) & 255);
	color.g = ((pixel_color >> 8) & 255);
	color.b = (pixel_color & 255);
	color.r *= 1 - smog;
	color.g *= 1 - smog;
	color.b *= 1 - smog;
	return (((256 * 256 * color.r) + (256 * color.g) + color.b));
}
