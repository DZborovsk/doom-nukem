/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:06:12 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:06:14 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		help_up_cards(t_my_doom *my, unsigned int *pxl,
		SDL_Surface *pic_surface, int num)
{
	int				x;
	int				y;

	y = -1;
	while (++y < 48)
	{
		x = -1;
		my->duk_draw.dr_car[num][y] = (int *)malloc(sizeof(int) * 52);
		while (++x < 52)
			my->duk_draw.dr_car[num][y][x] = pxl[(y * pic_surface->w) + x];
	}
	SDL_FreeSurface(pic_surface);
}

void		dw_cards(t_my_doom *my, int num, char *path)
{
	SDL_Surface		*pic_surface;
	unsigned int	*pxl;

	pic_surface = IMG_Load(path);
	if (!pic_surface)
	{
		ft_putendl(IMG_GetError());
		return ;
	}
	my->duk_draw.dr_car[num] = (int**)malloc(sizeof(int *) * 48);
	pxl = (unsigned int *)pic_surface->pixels;
	help_up_cards(my, pxl, pic_surface, num);
}

void		help_up_items(t_my_doom *my, unsigned int *pxl,
		SDL_Surface *pic_surface, int num)
{
	int				y;
	int				x;

	y = -1;
	while (++y < 100)
	{
		x = -1;
		my->duk_draw.item[num][y] = (int *)malloc(sizeof(int) * 100);
		while (++x < 100)
			my->duk_draw.item[num][y][x] = pxl[(y * pic_surface->w) + x];
	}
	SDL_FreeSurface(pic_surface);
}

void		dw_item(t_my_doom *my, int num, char *path)
{
	SDL_Surface		*pic_surface;
	unsigned int	*pxl;

	pic_surface = IMG_Load(path);
	if (!pic_surface)
	{
		ft_putendl(IMG_GetError());
		return ;
	}
	my->duk_draw.item[num] = (int**)malloc(sizeof(int *) * 100);
	pxl = (unsigned int *)pic_surface->pixels;
	help_up_items(my, pxl, pic_surface, num);
}
