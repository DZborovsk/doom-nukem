/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_png.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:09:10 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:09:12 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	u_all_cards(t_my_doom *d)
{
	dw_cards(d, 2, "media/sprites/items/pokeball.png");
	dw_cards(d, 1, "media/sprites/items/key.png");
}

void	u_all_items(t_my_doom *d)
{
	dw_item(d, 0, "media/sprites/items/medical.png");
	dw_item(d, 1, "media/sprites/items/wp.png");
	dw_item(d, 2, "media/sprites/items/jetpack.png");
}

void	u_all_enemies(t_my_doom *d)
{
	dw_item(d, 3, "media/sprites/enemy/Imp_1.png");
	dw_item(d, 4, "media/sprites/enemy/Imp_2.png");
	dw_item(d, 5, "media/sprites/enemy/Imp_3.png");
	dw_item(d, 6, "media/sprites/enemy/Imp_4.png");
	dw_item(d, 7, "media/sprites/enemy/Imp_5.png");
	dw_item(d, 8, "media/sprites/enemy/Imp_6.png");
	dw_item(d, 9, "media/sprites/enemy/Imp_7.png");
	dw_item(d, 10, "media/sprites/enemy/Imp_8.png");
}

int		load_items(t_my_doom *d)
{
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		ft_putendl(IMG_GetError());
	}
	d->duk_draw.dr_car = (int***)malloc(sizeof(int **) * 3);
	u_all_cards(d);
	d->duk_draw.item = (int***)malloc(sizeof(int **) * 12);
	u_all_items(d);
	u_all_enemies(d);
	return (1);
}
