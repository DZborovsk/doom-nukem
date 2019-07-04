/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helmet_draw_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:23:00 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:23:46 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_keys(t_my_doom *d, int key, int x, int y)
{
	float		k;
	float		r;
	float		rotate;
	int			c_x;
	int			c_y;

	k = 0;
	c_y = y;
	rotate = 1.3;
	while (c_y < HEIGHT && k < 48)
	{
		r = 0;
		c_x = x;
		while (c_x < WIDTH && r < 52)
		{
			if (r < 52 && k < 48)
				if (d->duk_draw.dr_car[key][(int)k][(int)r] != 0x000000)
					d->duk_draw.dr_img[c_y][c_x] =
						d->duk_draw.dr_car[key][(int)k][(int)r];
			r = r + rotate;
			c_x++;
		}
		k = k + rotate;
		c_y++;
	}
}

void	draw_inventory_pics(t_my_doom *d)
{
	int j;
	int k;

	j = 200;
	k = WIDTH - 150;
	if (d->dk_user.invspr.dr_key == 1)
	{
		draw_keys(d, 1, k, j);
		j = j + 50;
	}
	if (d->dk_user.invspr.gr_key == 1)
	{
		draw_keys(d, 2, k, j);
		j = j + 50;
	}
}

void	draw_inventory(t_my_doom *d, SDL_Color c, int y)
{
	if (d->dk_user.invspr.dr_key == 1)
	{
		draw_keys(d, 1, 1050 - 50, y);
		ft_text_write(d, "Door key",
				set_pixel_txt(1050, y, c, 20), "media/fonts/Special.ttf");
		y = y + 50;
	}
	if (d->dk_user.invspr.gr_key == 1)
	{
		draw_keys(d, 2, 1050 - 50, y);
		ft_text_write(d, "Pokeball",
				set_pixel_txt(1050, y, c, 20), "media/fonts/Special.ttf");
		y = y + 50;
	}
}

void	draw_lift_stuff(t_my_doom *d)
{
	SDL_Color	c;

	if (0 < d->duk_sec[d->dk_user.us_sec].lift)
	{
		if (d->dk_user.invspr.gr_key == 0)
		{
			c.r = 150;
			c.g = 0;
			c.b = 0;
			ft_text_write(d, "ACCESS DENIED",
				set_pixel_txt(200, 200, c, 50), "media/fonts/Special.ttf");
			ft_text_write(d, "To use lift you need pokeball",
				set_pixel_txt(200, 250, c, 20), "media/fonts/Special.ttf");
		}
		else if (d->dk_user.invspr.gr_key == 1)
		{
			c.r = 0;
			c.g = 150;
			c.b = 0;
			ft_text_write(d, "ACCESSED",
				set_pixel_txt(200, 200, c, 50), "media/fonts/Special.ttf");
			ft_text_write(d, "To use lift press: G key",
				set_pixel_txt(200, 250, c, 20), "media/fonts/Special.ttf");
		}
	}
}

int		load_helmet_view(t_my_doom *dat)
{
	int				y;
	SDL_Surface		*pic_surface;

	dat->duk_draw.dr_he = (int**)malloc(sizeof(int*) * HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		dat->duk_draw.dr_he[y] = (int*)malloc(sizeof(int) * WIDTH);
		y++;
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		ft_putendl(IMG_GetError());
	}
	pic_surface = IMG_Load("media/hud_main.png");
	if (!pic_surface)
	{
		ft_putendl(IMG_GetError());
		return (-1);
	}
	load_helmet_view_data(dat, pic_surface);
	SDL_FreeSurface(pic_surface);
	return (1);
}
