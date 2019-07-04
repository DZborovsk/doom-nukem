/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:12:52 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:12:54 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_aim(t_my_doom *d)
{
	t_post	start_cross;
	t_post	end_cross;
	int		color;

	color = 0x66ff22;
	start_cross.x = 600;
	start_cross.y = 390;
	end_cross.x = 600;
	end_cross.y = 380;
	draw_line_doom(d, start_cross, end_cross, color);
	start_cross.y = 425;
	end_cross.y = 410;
	draw_line_doom(d, start_cross, end_cross, color);
	start_cross.x = 590;
	start_cross.y = 400;
	end_cross.x = 580;
	end_cross.y = 400;
	draw_line_doom(d, start_cross, end_cross, color);
	start_cross.x = 610;
	end_cross.x = 620;
	draw_line_doom(d, start_cross, end_cross, color);
}
