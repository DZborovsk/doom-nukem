/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:10:30 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:10:31 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	unload_data(t_my_doom *my)
{
	unsigned int i;

	i = -1;
	while (++i < my->duk_draw.sec_num)
	{
		free(my->duk_sec[i].d_top);
	}
	i = -1;
	while (++i < my->duk_draw.sec_num)
	{
		free(my->duk_sec[i].n_bor);
	}
	free(my->duk_sec);
}

void	doom_quit(int flag, t_my_doom *my)
{
	if (flag == 1)
	{
		unload_data(my);
	}
	sdl_quit_doom(my, 1);
}
