/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:24:01 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:24:02 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"


int	ft_q(float m0, float m1, float q0, float q1)
{
	if (f_min(m0, m1) <= f_max(q0, q1))
		if (f_min(q0, q1) <= f_max(m0, m1))
			return  (1);
	return (0);

}

int ft_doom_s(t_my_doom *my, int s)
{
	float		z;
	float		m;
	t_lin2		*vert;
	t_room		*sect;

	sect = &my->duk_sec[my->dk_user.us_sec];
	vert = sect->d_top;
	z = my->dk_user.where.x;
	m = my->dk_user.where.y;
	if ((ft_q(z, m, my->duk_gm.dx, my->duk_gm.dy)) &&
	ft_q(vert[s + 0].x, vert[s + 0].y, vert[s + 1].x, vert[s + 1].y))
		return (1);
	return  (0);
}



void	help_doom_move(t_my_doom *my, float dx, float dy)
{
	int			s;
	t_room		*sect;
	t_lin2		*vert;
	float		px;
	float		py;

	s = -1;
	px = my->dk_user.where.x;
	py = my->dk_user.where.y;
	sect = &my->duk_sec[my->dk_user.us_sec];
	vert = sect->d_top;
	my->duk_gm.dx = (px + dx);
	my->duk_gm.dy = (py + dy);
	while (++s < (int)sect->num_p)
		if (sect->n_bor[s] >= 0
			&& ft_doom_s(my, s) &&
			point_side_fl(ft_map_help(px + dx, py + dy, vert[s + 0].x),
					vert[s + 0].y, vert[s + 1].x, vert[s + 1].y) < 0)
		{
			my->dk_user.us_sec = sect->n_bor[s];
			break ;
		}
}

void	doom_move_player(t_my_doom *my, float dx, float dy)
{
	float		res_sinf;
	float		res_cosf;

	help_doom_move(my, dx, dy);
	my->dk_user.where.x += dx;
	my->dk_user.where.y += dy;
	res_sinf = sinf(my->dk_user.us_ang);
	res_cosf = cosf(my->dk_user.us_ang);
	my->dk_user.sin_an = res_sinf;
	my->dk_user.cos_an = res_cosf;
}

void	doom_main_keys(t_my_doom *my)
{
	float speed_i;
	float speed_j;

	speed_i = 0.05;
	speed_j = 0.03;
	SDL_GetRelativeMouseState(&my->duk_gm.x_m, &my->duk_gm.y_m);
	my->dk_user.us_ang += my->duk_gm.x_m * speed_j;
	my->duk_gm.yaw = clamp_float(my->duk_gm.yaw -
			my->duk_gm.y_m * speed_i, -5, 5);
	my->dk_user.yaw = -1 * (my->duk_gm.yaw -
			my->dk_user.us_sp.z * 0.9f);
	doom_move_player(my, 0, 0);
}
