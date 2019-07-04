/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:15:38 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:15:41 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_fps(t_my_doom *doom_fps)
{
	static int		my_time;
	static int		fps;
	static int		my_fps;
	char			*s;

	if (time(NULL) != my_time)
	{
		my_fps = fps;
		fps = 0;
		my_time = (int)time(NULL);
	}
	else
		fps++;
	s = ft_itoa(my_fps);
	doom_fps->fps_show = ft_strjoin("FPS ", s);
	free(s);
}
