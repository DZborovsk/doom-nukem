/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:44:43 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:44:45 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	mission_msg(t_my_doom *dat)
{
	int			index;
	SDL_Color	color;

	index = 0;
	while (20 > index)
	{
		color.r = color.r + 10;
		color.b = color.b + 5;
		SDL_RenderClear(dat->duk_ren);
		ft_text_write(dat, "Mission X: Find pink sector",
			set_pixel_txt(275, 250, color, 40), "media/fonts/Special.ttf");
		SDL_RenderPresent(dat->duk_ren);
		SDL_Delay(150);
		index++;
	}
	Mix_PlayMusic(dat->mus, -1);
}

void	final_score_msg(t_my_doom *dat)
{
	char		*s;
	SDL_Color	clr;
	int			i;

	i = 0;
	while (i < 20)
	{
		clr.r = 10 + clr.r;
		clr.b = 5 + clr.b;
		ft_text_write(dat, "Mission X completed",
			set_pixel_txt(250, 600, clr, 40), "media/fonts/Special.ttf");
		ft_text_write(dat, "ITEMS :  ", set_pixel_txt(100, 700, clr, 30), "media/fonts/Special.ttf");
		ft_text_write(dat, "KILLS :  ", set_pixel_txt(100, 730, clr, 30), "media/fonts/Special.ttf");
		s = ft_itoa(dat->monst_death);
		ft_text_write(dat, s, set_pixel_txt(250, 700, clr, 30), "media/fonts/Special.ttf");
		free(s);
		s = ft_itoa(dat->obj);
		ft_text_write(dat, s, set_pixel_txt(250, 730, clr, 30), "media/fonts/Special.ttf");
		free(s);
		SDL_RenderPresent(dat->duk_ren);
		SDL_Delay(200);
		i++;
	}
}

void	won_msg(t_my_doom *dat)
{
	int			index;
	SDL_Color	c;

	index = 0;
	while (index < 20)
	{
		c.r = 120 + c.r;
		c.b = 68 + c.b;
		SDL_RenderClear(dat->duk_ren);
		ft_text_write(dat, "YOU WIN", set_pixel_txt(385, 305, c, 100), "media/fonts/Special.ttf");
		SDL_RenderPresent(dat->duk_ren);
		SDL_Delay(150);
		index++;
	}
	final_score_msg(dat);
	SDL_Delay(950);
}

void	doom_died_msg(t_my_doom *dat)
{
	int			index;
	SDL_Color	c;

	if (dat->duk_sec[dat->dk_user.us_sec].end == 1)
	{
		won_msg(dat);
	}
	else
	{
		index = 0;
		while (20 > index)
		{
			c.r = 10 + c.r;
			SDL_RenderClear(dat->duk_ren);
			ft_text_write(dat, "YOU DIED",
				set_pixel_txt(450, 290, c, 100), "media/fonts/Special.ttf");
			SDL_RenderPresent(dat->duk_ren);
			SDL_Delay(150);
			index++;
		}
		SDL_Delay(200);
	}
}

int		calc_dmg_doom(t_my_doom *d)
{
	if (d->duk_sec[d->dk_user.us_sec].floor >=
		d->duk_sec[d->dk_user.us_sec].ceil)
	{
		d->dk_user.invspr.hp = d->dk_user.invspr.hp - 10;
	}
	if (0 >= d->dk_user.invspr.hp)
	{
		return (-1);
	}
	if (1 == d->duk_sec[d->dk_user.us_sec].end)
	{
		return (-1);
	}
	return (1);
}
