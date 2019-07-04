/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:10:06 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:10:09 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void				doom_init(t_my_doom *main)
{
	main->duk_gm.num_v[1] = 0.f;
	main->dk_user.invspr.gr_key = 0;
	main->dk_user.invspr.dr_key = 0;
	main->dk_user.invspr.ammo = 100;
	main->duk_gm.gr_d = 0;
	main->duk_gm.f_ng = 1;
	main->duk_gm.m_ng = 0;
	main->duk_gm.n_duc = 0;
	main->duk_gm.yaw = 0;
	main->duk_gm.n_fly = 0;
	main->md_d = 0;
	main->flag = 0;
	main->time = SDL_GetTicks();
	main->obj = 0;
	main->monst_death = 0;
	main->duk_gm.m_wi = 0;
	main->duk_draw.tini.i_win = 0;
	main->dk_user.invspr.i_we_mh = 0;
	main->duk_gm.num_v[0] = 0.f;
}

Mix_Music			*download_music(char *track)
{
	Mix_Music *doom_music;

	doom_music = Mix_LoadMUS(track);
	if (doom_music == 0)
	{
		ft_putendl("error music ");
	}
	return (doom_music);
}

int					load_sounds_doom(t_my_doom *main)
{
	if (0 > Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
		return (0);
	main->mus = download_music("media/sounds/main_sound.mp3");
	main->guns[0] = Mix_LoadWAV("media/sounds/weapon_1.mp3");
	main->guns[1] = Mix_LoadWAV("media/sounds/weapon_2.mp3");
	main->mus2 = download_music("media/sounds/bg_sound.mp3");
	return (1);
}

void				load_texture_doom(t_my_doom *main)
{
	int y;
	int i;

	i = 15;
	main->duk_draw.txs = (int **)malloc(sizeof(int *) * i);
	y = 0;
	while (y < i)
	{
		main->duk_draw.txs[y] = (int *)malloc(sizeof(int) * (int)(128 * 128));
		y++;
	}
	load_png_doom(main, 0, "media/textures/tree.png");
	load_png_doom(main, 1, "media/textures/marble.png");
	load_png_doom(main, 2, "media/textures/brick.png");
	load_png_doom(main, 3, "media/textures/door.png");
	load_png_doom(main, 4, "media/textures/window.png");
	load_png_doom(main, 5, "media/textures/red_grid.png");
	load_png_doom(main, 6, "media/textures/gren_grid.png");
}

void				doom_init_backup(t_my_doom *main)
{
	int i;
	int j;

	i = 0;
	main->duk_draw.buf_im = (int **)malloc(sizeof(int *) * HEIGHT);
	while (HEIGHT > i)
	{
		j = 0;
		main->duk_draw.buf_im[i] = (int *)malloc(sizeof(int) * WIDTH);
		while (WIDTH > j)
		{
			main->duk_draw.buf_im[i][j] = 0x111111;
			j++;
		}
		i++;
	}
}
