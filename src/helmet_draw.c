/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helmet_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:26:00 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:28:06 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_helmet_view_data(t_my_doom *dat, SDL_Surface *pic_surface)
{
	int				x;
	int				y;
	unsigned int	*pixels;

	pixels = (unsigned int *)pic_surface->pixels;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			dat->duk_draw.dr_he[y][x] = pixels[x + (y * pic_surface->w)];
			x++;
		}
		y++;
	}
}

void	draw_helmet_pix(t_my_doom *dat)
{
	int x;
	int y;

	y = 0;
	while (HEIGHT > y)
	{
		x = 0;
		while (WIDTH > x)
		{
			if (dat->duk_draw.dr_he[y][x] != 0x000000)
			{
				dat->duk_draw.dr_img[y][x] = dat->duk_draw.dr_he[y][x];
			}
			x++;
		}
		y++;
	}
}

void	draw_hud_2(t_my_doom *d, SDL_Color color)
{
	if (d->md_d == 1)
		draw_inventory(d, color, 100);
	else
		draw_inventory_pics(d);
	draw_lift_stuff(d);
}

void help_hud(t_my_doom *d, char *buff, char *buff2)
{
	SDL_Color	color;

	color.r = 168;
	color.g = 100;
	color.b = 57;
	buff = ft_itoa((int)d->dk_user.invspr.hp);
	buff2 = d->fps_show;
	ft_text_write(d, buff, set_pixel_txt(510,
										 HEIGHT - 20, color, 20), "media/fonts/Special.ttf");
	ft_strdel(&buff);
	buff = ft_itoa((int)d->dk_user.invspr.armor);
	ft_text_write(d, buff, set_pixel_txt(655, HEIGHT - 20, color, 20),
				  "media/fonts/Special.ttf");
	ft_text_write(d, buff2, set_pixel_txt(1050, HEIGHT - 670, color, 25),
				  "media/fonts/Special.ttf");
	ft_strdel(&buff);
	ft_strdel(&buff2);
}
void	draw_hud(t_my_doom *d)
{
	char		*buff;
	char		*buff2;
	SDL_Color	color;

	color.r = 168;
	color.g = 100;
	color.b = 57;
	buff = NULL;
	buff2 = d->fps_show;
	help_hud(d, buff, buff2);
	if (d->dk_user.invspr.i_we_tp == 1 || d->dk_user.invspr.i_we_tp == 2)
	{
		buff = ft_itoa((int)d->dk_user.invspr.ammo);
		ft_text_write(d, buff, set_pixel_txt(580,
					HEIGHT - 20, color, 20), "media/fonts/Special.ttf");
		ft_strdel(&buff);
	}
	draw_hud_2(d, color);
}
