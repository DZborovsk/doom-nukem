/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:26:09 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:26:10 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_duk_br	ft_math_magic(t_post start_magic, t_post end_magic)
{
	t_duk_br calcul;

	calcul.a = end_magic.y - start_magic.y;
	calcul.b = start_magic.x - end_magic.x;
	calcul.a_sn = calcul.a < 0 ? -1 : 1;
	calcul.b_sn = calcul.b < 0 ? -1 : 1;
	calcul.f = 0;
	calcul.x = start_magic.x;
	calcul.y = start_magic.y;
	calcul.en_dr = end_magic.x;
	calcul.y_end = end_magic.y;
	return (calcul);
}

void		draw_line_doom(t_my_doom *main, t_post start_magic,
	t_post end, int color)
{
	t_duk_br calcul;

	calcul = ft_math_magic(start_magic, end);
	if (ft_abs(calcul.a) < ft_abs(calcul.b))
	{
		while (calcul.x != calcul.en_dr || calcul.y != calcul.y_end)
		{
			calcul.f += (calcul.a * calcul.a_sn);
			if (calcul.f > 0)
			{
				calcul.f -= (calcul.b * calcul.b_sn);
				calcul.y += calcul.a_sn;
			}
			calcul.x -= calcul.b_sn;
			if (calcul.y > 0 && calcul.y < HEIGHT &&
			calcul.x > 0 && calcul.x < WIDTH)
				main->duk_draw.dr_img[calcul.y][calcul.x] = color;
		}
	}
	else
		ft_help_math(calcul, main, color);
}
