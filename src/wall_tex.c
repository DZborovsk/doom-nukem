/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:24:45 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:24:47 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		draw_textures_wall(t_my_doom *main)
{
	int tmp_texture;

	if (main->duk_gm.m_wi == 0)
		return ;
	main->duk_draw.tini.s = -1;
	if (main->duk_gm.m_wi == 1)
		main->duk_draw.tini.i_win = 1;
	tmp_texture = main->duk_draw.mat.sect->num_t;
	main->duk_draw.mat.sect->num_t = 4;
	while (main->duk_draw.tini.s < main->duk_draw.mat.sect->num_p)
	{
		player_calc_view(main);
		if (main->duk_draw.mat.z_1 <= 0 && main->duk_draw.mat.z_2 <= 0)
			break ;
		wall_intersec(main);
		perspect_trans(main);
		if (main->duk_draw.mat.x1 >= main->duk_draw.mat.x2 ||
		main->duk_draw.mat.x2 < main->duk_draw.mat.now.sx1 ||
		main->duk_draw.mat.x1 > main->duk_draw.mat.now.sx2)
			break ;
		texture_full_wall(main);
		++main->duk_draw.tini.s;
	}
	main->duk_draw.mat.sect->num_t = tmp_texture;
	main->duk_draw.tini.i_win = 0;
}
