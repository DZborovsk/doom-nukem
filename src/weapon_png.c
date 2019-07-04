/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_png.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:02:43 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:02:50 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

SDL_Surface		*dw_shotgun_part(int img)
{
	SDL_Surface *pic_surf;

	if (img == 0)
		pic_surf = IMG_Load("media/sprites/weapons/gun_1.png");
	if (img == 1)
		pic_surf = IMG_Load("media/sprites/weapons/gun_2.png");
	if (img == 2)
		pic_surf = IMG_Load("media/sprites/weapons/gun_3.png");
	if (img == 3)
		pic_surf = IMG_Load("media/sprites/weapons/gun_4.png");
	if (img == 4)
		pic_surf = IMG_Load("media/sprites/weapons/gun_5.png");
	if (img == 5)
		pic_surf = IMG_Load("media/sprites/weapons/gun_6.png");
	if (img == 6)
		pic_surf = IMG_Load("media/sprites/weapons/gun_7.png");
	if (img == 7)
		pic_surf = IMG_Load("media/sprites/weapons/gun_8.png");
	if (img == 8)
		pic_surf = IMG_Load("media/sprites/weapons/gun_9.png");
	return (pic_surf);
}

void			help_dw_shotgun(t_my_doom *my, int img,
		SDL_Surface *pic_surf, unsigned int *pxl)
{
	int				x;
	int				y;

	y = -1;
	while (++y < 178)
	{
		x = -1;
		while (++x < 178)
			my->duk_draw.shun[img][y][x] = pxl[(y * pic_surf->w) + x];
	}
	SDL_FreeSurface(pic_surf);
}

void			dw_shotgun(t_my_doom *my, int img)
{
	SDL_Surface		*pic_surf;
	unsigned int	*pxl;

	pic_surf = dw_shotgun_part(img);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	if (!pic_surf)
	{
		ft_putendl(IMG_GetError());
		return ;
	}
	pxl = (unsigned int *)pic_surf->pixels;
	help_dw_shotgun(my, img, pic_surf, pxl);
}

SDL_Surface		*dw_blaster_part(int img)
{
	SDL_Surface *pic_surf;

	if (img == 0)
		pic_surf = IMG_Load("media/sprites/weapons/blaster_1.png");
	if (img == 1)
		pic_surf = IMG_Load("media/sprites/weapons/blaster_2.png");
	if (img == 2)
		pic_surf = IMG_Load("media/sprites/weapons/blaster_3.png");
	if (img == 3)
		pic_surf = IMG_Load("media/sprites/weapons/blaster_4.png");
	if (img == 4)
		pic_surf = IMG_Load("media/sprites/weapons/blaster_5.png");
	if (img == 5)
		pic_surf = IMG_Load("media/sprites/weapons/blaster_6.png");
	return (pic_surf);
}

void			dw_blaster(t_my_doom *d, int img)
{
	SDL_Surface		*pic_surf;
	unsigned int	*pxl;
	int				x;
	int				y;

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	pic_surf = dw_blaster_part(img);
	if (!pic_surf)
	{
		ft_putendl(IMG_GetError());
		return ;
	}
	pxl = (unsigned int *)pic_surf->pixels;
	y = -1;
	while (++y < 128)
	{
		x = -1;
		while (++x < 128)
			d->duk_draw.blast[img][y][x] = pxl[(y * pic_surf->w) + x];
	}
	SDL_FreeSurface(pic_surf);
}
