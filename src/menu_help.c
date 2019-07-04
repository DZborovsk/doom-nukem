/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:03:57 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:04:15 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

SDL_Surface		*load_image(char *s)
{
	SDL_Surface *tex;

	tex = IMG_Load(s);
	if (tex == NULL)
		exit(1);
	return (tex);
}

unsigned int	get_px_int_doom(SDL_Surface *surface, int i, int j)
{
	unsigned int	*pxl;
	unsigned int	*res;

	res = NULL;
	pxl = (unsigned int*)surface->pixels;
	res = &pxl[(j * surface->w) + i];
	return (*res);
}

int				go_doom(t_my_doom *main, t_sour *data)
{
	main->run_gn = 1;
	doom_parser(data, main);
	go_doom_game(main);
	return (0);
}

void			draw_menu_doom(t_my_doom *main)
{
	int j;
	int i;
	int f;

	f = 1;
	j = -1;
	while (++j != HEIGHT - 1)
	{
		i = 0;
		while (++i != WIDTH - 1)
			main->duk_draw.dr_img[j][i] =
					get_px_int_doom(main->menu.menu, i, j);
		f++;
	}
}
