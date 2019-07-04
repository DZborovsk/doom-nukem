/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:03:00 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:03:02 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_symvl			set_pixel_txt(int a, int b, SDL_Color color, int size)
{
	t_symvl res;

	res.pos.x = a;
	res.pos.y = b;
	res.color = color;
	res.size = size;
	return (res);
}

void			help_drav_text(t_my_doom *main)
{
	SDL_RenderCopy(main->duk_ren, main->fonts.tx_fo, NULL, &main->fonts.rec_ft);
	SDL_DestroyTexture(main->fonts.tx_fo);
	SDL_FreeSurface(main->fonts.su_fo);
	TTF_CloseFont(main->fonts.ttf_ft);
}

void			ft_text_write(t_my_doom *main,
		char *text, t_symvl txt, char *font_path)
{
	int	text_w;
	int	text_h;

	if (!text)
		return ;
	if (txt.size < 1 || txt.size > 500)
		return ;
	main->fonts.ttf_ft = TTF_OpenFont(font_path, txt.size);
	if (!main->fonts.ttf_ft)
	{
		ft_putendl(SDL_GetError());
		return ;
	}
	main->fonts.su_fo =
			TTF_RenderText_Solid(main->fonts.ttf_ft, text, txt.color);
	main->fonts.tx_fo =
			SDL_CreateTextureFromSurface(main->duk_ren, main->fonts.su_fo);
	SDL_QueryTexture(main->fonts.tx_fo, NULL, NULL, &text_w, &text_h);
	main->fonts.rec_ft.x = txt.pos.x;
	main->fonts.rec_ft.y = txt.pos.y;
	main->fonts.rec_ft.w = text_w;
	main->fonts.rec_ft.h = text_h;
	help_drav_text(main);
}
