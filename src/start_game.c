/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:11:43 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:11:45 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	interact_obj(t_my_doom *dat)
{
	int vb;
	int c;
	int zs;
	int yu;
	int p;

	c = 0x005500;
	p = c;
	if (1 == dat->flag)
		c = 0x990000;
	zs = SDL_GetTicks();
	if (500 > (zs - dat->time))
	{
		yu = 0;
		while (HEIGHT > yu)
		{
			vb = -1;
			while (WIDTH > ++vb)
				dat->duk_draw.dr_img[yu][vb] = c + dat->duk_draw.dr_img[yu][vb];
			yu++;
		}
	}
	else
		dat->flag = 0;
}

void	doom_loop(t_my_doom *dat)
{
	doom_init(dat);
	dat->dk_user.invspr.shine = 1;
	check_sprites(dat);
	mission_msg(dat);
	while (1)
	{
		SDL_SetRelativeMouseMode(1);
		doom_render_meh(dat);
		doom_ingame_meh(dat);
		draw_sky_box(dat);
		draw_screen(dat);
		if (dat->duk_gm.gr_d == 1)
			draw_spritekit(dat);
		import_object(dat);
		draw_weapons(dat);
		draw_aim(dat);
		draw_helmet_pix(dat);
		if (dat->md_d == 0)
			draw_vectors(dat);
		draw_hud(dat);
		ft_fps(dat);
		SDL_RenderPresent(dat->duk_ren);
	}
	doom_died_msg(dat);
	doom_quit(1, dat);
}

void	died_doom(t_my_doom *dat)
{
	doom_died_msg(dat);
	doom_quit(1, dat);
}

void	go_doom_game(t_my_doom *dat)
{
	if (load_sounds_doom(dat) == 0)
	{
		doom_quit(1, dat);
	}
	load_texture_doom(dat);
	load_helmet_view(dat);
	load_weapons(dat);
	dat->dk_user.invspr.i_we_tp = 1;
	dat->dk_user.invspr.wea_ph = 1;
	load_items(dat);
	load_sky_pxl(dat, "media/skybox/sky_img.png");
	doom_init_backup(dat);
	if (p_doom_map(dat) != 1)
	{
		died_doom(dat);
	}
	doom_loop(dat);
	sdl_quit_doom(dat, 0);
}
