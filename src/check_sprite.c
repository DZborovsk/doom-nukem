/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:15:52 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 19:15:53 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	data_sprites(t_my_doom *dat, int cur, int png)
{
	dat->duk_sec[cur].sp_thi[png].c_sp_d =
		8 + dat->duk_sec[cur].sp_thi[png].f_sp_d;
	dat->duk_sec[cur].sp_thi[png].w_sp_d = 1;
	dat->duk_sec[cur].sp_thi[png].f_sp_d =
		dat->duk_sec[cur].floor;
	if (2 == dat->duk_sec[cur].sp_thi[png].id_sp_d
		|| 1 == dat->duk_sec[cur].sp_thi[png].id_sp_d)
	{
		dat->duk_sec[cur].sp_thi[png].hi_sp_d = 48;
		dat->duk_sec[cur].sp_thi[png].wi_sp_d = 52;
	}
	if (4 == dat->duk_sec[cur].sp_thi[png].id_sp_d
		|| 5
			== dat->duk_sec[cur].sp_thi[png].id_sp_d
		|| 3
			== dat->duk_sec[cur].sp_thi[png].id_sp_d)
	{
		dat->duk_sec[cur].sp_thi[png].hi_sp_d = 100;
		dat->duk_sec[cur].sp_thi[png].wi_sp_d = 100;
	}
	if (6 == dat->duk_sec[cur].sp_thi[png].id_sp_d)
	{
		dat->duk_sec[cur].sp_thi[png].hi_sp_d = 100;
		dat->duk_sec[cur].sp_thi[png].wi_sp_d = 100;
	}
}

void	check_sprites(t_my_doom *dat)
{
	int cur_sec;
	int cur_sprt;
	int max_sprite;

	cur_sec = 0;
	max_sprite = 5;
	while (dat->duk_draw.sec_num > (size_t)cur_sec)
	{
		cur_sprt = 0;
		while (max_sprite > cur_sprt)
		{
			if (dat->duk_sec[cur_sec].sp_thi[cur_sprt].id_sp_d
				!= -1)
			{
				data_sprites(dat, cur_sec, cur_sprt);
			}
			cur_sprt++;
		}
		cur_sec++;
	}
}

int		sprite_loading(t_my_doom *dat)
{
	int cur_sec;
	int cur_sprt;
	int max_sprite;

	cur_sec = 0;
	max_sprite = 5;
	while (dat->duk_draw.sec_num > (size_t)cur_sec)
	{
		cur_sprt = 0;
		dat->duk_sec[cur_sec].sp_thi =
			(t_spte*)malloc(sizeof(t_spte) * 5);
		while (max_sprite > cur_sprt)
		{
			dat->duk_sec[cur_sec].sp_thi[cur_sprt].id_sp_d =
				-1;
			cur_sprt++;
		}
		cur_sec++;
	}
	return (1);
}
