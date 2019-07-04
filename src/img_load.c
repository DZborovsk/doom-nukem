/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:12:24 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:12:29 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

unsigned int	get_pixel_int(SDL_Surface *surf, int x, int y)
{
	unsigned int *pix;

	pix = (unsigned int *)surf->pixels;
	return (pix[(y * surf->w) + x]);
}

int				ft_check_img(t_my_doom *main)
{
	main->flag_1 = 1;
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		ft_putendl(IMG_GetError());
		return (-1);
	}
	return (1);
}

SDL_Surface		*load_png_picture(char *path)
{
	SDL_Surface		*surf;

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	surf = IMG_Load(path);
	if (!surf)
	{
		ft_putendl(IMG_GetError());
		return (NULL);
	}
	return (surf);
}
