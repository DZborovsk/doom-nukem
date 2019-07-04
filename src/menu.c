/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:06:39 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:06:40 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				event_menu(t_my_doom *my, t_sour *data)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		(my->run_gn == 1) ? 0 : mouse_selector(my, event, data);
		if ((event.type == SDL_KEYDOWN && event.key.keysym.sym ==
		SDLK_ESCAPE) && my->menu.flag == 1)
			my->menu.flag = 0;
		else if ((event.type == SDL_KEYDOWN &&
		event.key.keysym.sym == SDLK_ESCAPE) || (event.type == SDL_QUIT))
			exit(1);
		else if (event.type == SDL_KEYDOWN &&
		(event.key.keysym.sym == SDLK_UP) && my->menu.m_n > 0)
			my->menu.m_n--;
		else if (event.type == SDL_KEYDOWN &&
		(event.key.keysym.sym == SDLK_DOWN) && my->menu.m_n < 2)
			my->menu.m_n++;
		else if (doom_ev_help(my, data, event) == 1)
			return (1);
		else if (event.key.keysym.sym == SDLK_RETURN && my->menu.m_n == 0
				&& my->menu.flag != 1)
			if (go_doom(my, data) == 1)
				return (1);
	}
	return (0);
}

static void		str_chang_menu(t_my_doom *my)
{
	if (my->menu.flag == 0)
	{
		my->menu.str[0] = "NEW GAME";
		my->menu.str[1] = "LEVELS";
		my->menu.str[2] = "EXIT";
	}
	else
	{
		my->menu.str[0] = "LEVEL 1";
		my->menu.str[1] = "";
		my->menu.str[2] = "LEVEL 2";
	}
}

void			draw_line_menu(t_my_doom *my)
{
	int q;

	q = -1;
	str_chang_menu(my);
	SDL_GetMouseState(&my->duk_gm.x_m, &my->duk_gm.y_m);
	while (++q != 3)
	{
		my->menu.col_m.r = 255;
		my->menu.col_m.g = 0;
		my->menu.col_m.b = 0;
		if (q == my->menu.m_n)
		{
			my->menu.col_m.r = 100;
			my->menu.col_m.g = 53;
			my->menu.col_m.b = 200;
		}
		ft_text_write(my, my->menu.str[q], set_pixel_txt(20, 620 + (q * 50),
			my->menu.col_m, 50), "media/fonts/Special.ttf");
	}
}

void			menu_doom(t_my_doom *my, t_sour *data)
{
	int q;

	q = 0;
	my->menu.m_n = 0;
	my->menu.flag = 0;
	my->menu.menu = load_image("./media/main_menu.png");
	while (q == 0)
	{
		doom_render_meh(my);
		if (event_menu(my, data) == 1)
			return ;
		draw_menu_doom(my);
		(my->run_gn == 1) ? 0 : draw_line_menu(my);
		SDL_RenderPresent(my->duk_ren);
	}
}
