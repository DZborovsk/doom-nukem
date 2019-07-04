/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:07:30 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:08:13 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	tex_sprt(t_my_doom *my)
{
	if (1 == my->duk_draw.mat.sect->sp_thi[my->duk_draw.dr_sp.n_spr].id_sp_d)
	{
		draw_sprt_key(my, 1);
	}
	if (2 == my->duk_draw.mat.sect->sp_thi[my->duk_draw.dr_sp.n_spr].id_sp_d)
	{
		draw_sprt_key(my, 2);
	}
	if (3 == my->duk_draw.mat.sect->sp_thi[my->duk_draw.dr_sp.n_spr].id_sp_d)
	{
		draw_item_sprite(my, 0);
	}
	if (4 == my->duk_draw.mat.sect->sp_thi[my->duk_draw.dr_sp.n_spr].id_sp_d)
	{
		draw_item_sprite(my, 1);
	}
	if (5 == my->duk_draw.mat.sect->sp_thi[my->duk_draw.dr_sp.n_spr].id_sp_d)
	{
		draw_item_sprite(my, 2);
	}
	if (6 == my->duk_draw.mat.sect->sp_thi[my->duk_draw.dr_sp.n_spr].id_sp_d)
	{
		draw_imp_stuff(my);
	}
}

void	help_drav_imp(t_my_doom *main)
{
	main->monst_death++;
	main->duk_draw.mat.sect->sp_thi[main->duk_draw.dr_sp.n_spr].id_sp_d = 5;
	main->duk_draw.mat.sect->sp_thi[main->duk_draw.dr_sp.n_spr].c_sp_d = 5
			+ main->duk_draw.mat.sect->
			sp_thi[main->duk_draw.dr_sp.n_spr].f_sp_d;
	main->dk_user.invspr.i_we_mh--;
}

int	ft_q2(float m0, float m1, float q0, float q1)
{
	if (f_min(m0, m1) <= f_max(q0, q1))
		if (f_min(q0, q1) <= f_max(m0, m1))
			return  (1);
	return (0);

}

int ft_doom_s2(t_my_doom *my, float d_x, float d_y, size_t n)
{
	if ((ft_q2(my->dk_user.where.x, my->dk_user.where.y,
			  my->dk_user.where.x + d_x, my->dk_user.where.y + d_y)) &&
			  ft_q2(my->duk_sec[my->dk_user.us_sec].d_top[n + 0].x,
			  		my->duk_sec[my->dk_user.us_sec].d_top[n + 0].y,
			  		my->duk_sec[my->dk_user.us_sec].d_top[n + 1].x,
			  		my->duk_sec[my->dk_user.us_sec].d_top[n + 1].y))
		return (1);
	return  (0);
}

int		bumps(t_my_doom *my, float d_x, float d_y, size_t n)
{
	if (ft_doom_s2(my, d_x, d_y, n)
		&& point_side_fl(ft_map_help(my->dk_user.where.x + d_x,
				my->dk_user.where.y + d_y,
		my->duk_sec[my->dk_user.us_sec].d_top[n + 0].x),
				my->duk_sec[my->dk_user.us_sec].d_top[n + 0].y,
		my->duk_sec[my->dk_user.us_sec].d_top[n + 1].x,
		my->duk_sec[my->dk_user.us_sec].d_top[n + 1].y) < 0)
		if ((my->duk_sec[my->dk_user.us_sec].n_bor[n] < 0 ? -9e9 :
			f_min(my->duk_sec[my->dk_user.us_sec].ceil,
					my->duk_sec[my->duk_sec[my->dk_user.us_sec].n_bor[n]].ceil))
			< my->dk_user.where.z + 1 ||
			(my->duk_sec[my->dk_user.us_sec].n_bor[n]
			< 0 ? 9e9 : f_max(my->duk_sec[my->dk_user.us_sec].floor,
			my->duk_sec[my->duk_sec[my->dk_user.us_sec].n_bor[n]].floor))
			> my->dk_user.where.z - my->duk_gm.n_eyht + 2)
			return (1);
	return (0);
}

int		change_line(char **fdfile, char **line)
{
	int		q;
	int		i;
	char	*str;
	char	*tmp;

	q = -1;
	i = 0;
	tmp = *fdfile;
	while (tmp[++q])
	{
		if (tmp[q] == '\n')
		{
			*line = ft_strsub(tmp, 0, q);
			i = q;
			while (tmp[i] != '\0')
				i++;
			str = ft_strsub(tmp, q + 1, i - q);
			*fdfile = ft_strdup(str);
			free(str);
			free(tmp);
			return (1);
		}
	}
	return (0);
}
