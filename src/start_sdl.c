/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:10:51 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:10:52 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	sdl_start_protocols(t_my_doom *main)
{
	int min;

	min = -1;
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		if ((main->window = SDL_CreateWindow("doom @unit factory project",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH,
				HEIGHT, SDL_WINDOW_FOREIGN)))
			if ((main->duk_ren = SDL_CreateRenderer(main->window, min,
					SDL_RENDERER_PRESENTVSYNC)))
				if ((main->duk_txr = SDL_CreateTexture(main->duk_ren,
						SDL_PIXELFORMAT_ARGB8888,
						SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
					return ;
	ft_putendl(SDL_GetError());
	sdl_quit_doom(main, 1);
}
