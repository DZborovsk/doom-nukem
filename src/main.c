/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:19:20 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:19:22 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		main(int argc, char **argv)
{
	t_my_doom		main;
	t_sour			*data;

	sdl_start_protocols(&main);
	init_start_doom(&main);
	TTF_Init();
	argc != 2 ? error_msg("Bad number parametr\n") : 1;
	if (!(data = (t_sour *)malloc(sizeof(t_sour))))
	{
		error_msg("Bad malloc :(\n");
		return (0);
	}
	data->name = argv[1];
	data->fd = open(data->name, O_DIRECTORY);
	data->fd >= 0 ? error_msg("it's directory\n") : 1;
	menu_doom(&main, data);
	return (0);
}
