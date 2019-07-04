/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:03:25 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:03:28 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	sky_verline(t_my_doom *main, int x, int start_x)
{
	int y1;
	int j;
	int sky_h;
	int sky_2;

	sky_h = 2150;
	sky_2 = 4300;
	y1 = (main->dk_user.yaw * 94) + 871;
	j = 0;
	while (HEIGHT > j)
	{
		if (sky_2 > start_x && sky_h > y1)
		{
			main->duk_draw.dr_img[j][x] = main->duk_draw.px_sky[y1][start_x];
		}
		else
		{
			main->duk_draw.dr_img[j][x] = 0x5d5f63;
		}
		j++;
		y1++;
	}
}

void	draw_sky_box(t_my_doom *main)
{
	int x2;
	int y;

	y = 0;
	if (0 >= main->dk_user.sin_an)
	{
		x2 = (int)(main->dk_user.cos_an /
			(2.0 / 360.0) * ((double)4300 / 2 / 360.0));
	}
	else
		x2 = (int)(4300 / 2 - (main->dk_user.cos_an / (2 / 360.0)
					* ((double)4300 / 2 / 360.0)));
	if (0 > x2)
		x2 = 4320 + x2;
	while (y < WIDTH)
	{
		x2++;
		if (0 > x2)
			x2 = 4300;
		if (4300 < x2)
			x2 = 0;
		sky_verline(main, y, x2);
		y++;
	}
}

void	load_sky_l(t_my_doom *main, SDL_Surface *pic_surface)
{
	unsigned int	*pixels;
	int				x1;
	int				y;
	int				sky;
	int				sky_2;

	sky = 2150;
	sky_2 = 4300;
	pixels = (unsigned int *)pic_surface->pixels;
	y = 0;
	while (sky > y)
	{
		main->duk_draw.px_sky[y] = (int *)malloc(sizeof(int) * sky_2);
		x1 = 0;
		while (x1 < sky_2)
		{
			main->duk_draw.px_sky[y][x1] = pixels[(y * pic_surface->w) + x1];
			x1++;
		}
		y++;
	}
}

int		load_sky_pxl(t_my_doom *main, char *p)
{
	SDL_Surface		*pic_surface;
	int				sky;

	sky = 2150;
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		ft_putendl(IMG_GetError());
	}
	pic_surface = IMG_Load(p);
	if (!(pic_surface))
	{
		ft_putendl("Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	main->duk_draw.px_sky = (int **)malloc(sizeof(int *) * sky);
	load_sky_l(main, pic_surface);
	SDL_FreeSurface(pic_surface);
	return (1);
}
