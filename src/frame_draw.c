/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:07:03 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:07:05 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			draw_pre_frame(t_my_doom *main)
{
	int a;
	int b;

	b = 0;
	while (HEIGHT > b)
	{
		a = 0;
		while (WIDTH > a)
		{
			main->duk_draw.dr_img[b][a] = main->duk_draw.buf_im[b][a];
			a++;
		}
		b++;
	}
}

void			cur_frame(t_my_doom *main)
{
	int a;
	int b;

	b = 0;
	while (b < HEIGHT)
	{
		a = 0;
		while (a < WIDTH)
		{
			main->duk_draw.buf_im[b][a] = main->duk_draw.dr_img[b][a];
			a++;
		}
		b++;
	}
}
