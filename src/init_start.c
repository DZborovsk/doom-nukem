/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:08:42 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:08:44 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_start_doom(t_my_doom *main)
{
	main->run_gn = 0;
	main->duk_draw.sec_num = 0;
	main->duk_sec = NULL;
	main->dk_user.invspr.gravity = 0;
	main->st_key = SDL_GetKeyboardState(NULL);
	SDL_ShowCursor(SDL_ENABLE);
	main->f = 128;
}
