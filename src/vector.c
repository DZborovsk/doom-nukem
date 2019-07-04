/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:59:43 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:59:45 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		draw_sector_doom(t_my_doom *main, t_room sector, int color)
{
	int		vert_x;
	int		vert_y;
	size_t	i;
	t_post	start_drav;
	t_post	end_drav;

	i = 0;
	while (i < sector.num_p)
	{
		vert_x = 150 - (int)(main->dk_user.where.x - sector.d_top[i].x) * 5;
		vert_y = 148 - (int)(main->dk_user.where.y - sector.d_top[i].y) * 5;
		start_drav.x = vert_x;
		start_drav.y = vert_y;
		if (i > 0)
			draw_line_doom(main, start_drav, end_drav, color);
		end_drav = start_drav;
		++i;
	}
	vert_x = 150 - (int)(main->dk_user.where.x - sector.d_top[0].x) * 5;
	vert_y = 148 - (int)(main->dk_user.where.y - sector.d_top[0].y) * 5;
	start_drav.x = vert_x;
	start_drav.y = vert_y;
	draw_line_doom(main, start_drav, end_drav, color);
}

void		draw_vectors(t_my_doom *main)
{
	int		player_x;
	int		player_y;
	size_t	i;
	t_post	start_drav;
	t_post	end_drav;

	i = 0;
	player_x = WIDTH - 1050;
	player_y = HEIGHT - 650;
	main->duk_draw.dr_img[player_y][player_x] = 0xFF0000;
	while (i < main->duk_sec[main->dk_user.us_sec].num_p)
	{
		if (main->duk_sec[main->dk_user.us_sec].n_bor[i] >= 0)
			draw_sector_doom(main, main->duk_sec[main->
			duk_sec[main->dk_user.us_sec].n_bor[i]], 0x660066);
		++i;
	}
	draw_sector_doom(main, main->duk_sec[main->dk_user.us_sec], 0xffcc00);
	start_drav.x = player_x + 25 * cos(main->dk_user.us_ang);
	start_drav.y = player_y + 25 * sin(main->dk_user.us_ang);
	end_drav.x = player_x;
	end_drav.y = player_y;
	draw_line_doom(main, start_drav, end_drav, 0x00008B);
}
