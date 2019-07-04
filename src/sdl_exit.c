/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:17:04 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:17:20 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	sdl_quit_doom(t_my_doom *main, int e)
{
	if (main->duk_txr != NULL)
		SDL_DestroyTexture(main->duk_txr);
	SDL_DestroyRenderer(main->duk_ren);
	SDL_DestroyWindow(main->window);
	SDL_Quit();
	exit(e);
}
