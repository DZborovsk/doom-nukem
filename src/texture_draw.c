/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:02:32 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:02:34 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

float		yaw(t_my_doom *main, float y, float z)
{
	return (main->dk_user.yaw * z + y);
}

void		help_tex_floor(t_my_doom *main)
{
	main->duk_draw.mat.cl_fl = 0;
	vline(main, set_point(main->duk_draw.mat.x, main->duk_draw.
	t_y[main->duk_draw.mat.x], main->duk_draw.mat.cy_a - 1),
			set_point(0x111111, 0x222222, 0x111111));
}

void		tex_on_floor(t_my_doom *main)
{
	main->duk_draw.mat.cl_fl = 0;
	if (0 < main->duk_sec[main->duk_draw.mat.now.sectorno].door)
	{
		vline(main, set_point(main->duk_draw.mat.x, main->duk_draw.
		t_y[main->duk_draw.mat.x],
			main->duk_draw.mat.cy_a - 1),
					set_point(0x111111, 0x260600, 0x111111));
	}
	else if (0 < main->duk_sec[main->duk_draw.mat.now.sectorno].lift)
	{
		vline(main, set_point(main->duk_draw.mat.x, main->duk_draw.
		t_y[main->duk_draw.mat.x],
			main->duk_draw.mat.cy_a - 1),
					set_point(0x111111, 0x002000, 0x111111));
	}
	else if (main->duk_sec[main->duk_draw.mat.now.sectorno].end == 1)
	{
		vline(main, set_point(main->duk_draw.mat.x, main->duk_draw.
		t_y[main->duk_draw.mat.x],
			main->duk_draw.mat.cy_a - 1),
					set_point(0xfffffff, 0xfffffff, 0xfffffff));
	}
	else
		help_tex_floor(main);
}

void		tex_on_ceil(t_my_doom *main)
{
	main->duk_draw.mat.cl_fl = 1;
	if (0 < main->duk_sec[main->duk_draw.mat.now.sectorno].door)
	{
		vline(main, set_point(main->duk_draw.mat.x, main->duk_draw.mat.cy_b + 1,
			main->duk_draw.botm_y[main->duk_draw.mat.x]),
					set_point(0x000044, 0x260600, 0x000044));
	}
	else if (0 < main->duk_sec[main->duk_draw.mat.now.sectorno].lift)
	{
		vline(main, set_point(main->duk_draw.mat.x, main->duk_draw.mat.cy_b + 1,
			main->duk_draw.botm_y[main->duk_draw.mat.x]),
					set_point(0x000044, 0x002802, 0x000044));
	}
	else if (main->duk_sec[main->duk_draw.mat.now.sectorno].end == 1)
	{
		vline(main, set_point(main->duk_draw.mat.x, main->duk_draw.mat.cy_b + 1,
			main->duk_draw.botm_y[main->duk_draw.mat.x]),
					set_point(0x6600cc, 0x663366, 0x230030));
	}
	else
	{
		vline(main, set_point(main->duk_draw.mat.x, main->duk_draw.mat.cy_b + 1,
			main->duk_draw.botm_y[main->duk_draw.mat.x]),
					set_point(0x800000, 0x230030, 0x230030));
	}
}

void		tex_on_wall(t_my_doom *main)
{
	if (0 < main->duk_sec[main->duk_draw.mat.now.sectorno].door)
	{
		vline_tex(main, set_point(main->duk_draw.mat.x,
				main->duk_draw.mat.cy_a, main->duk_draw.mat.cy_b), 5);
	}
	else if (0 < main->duk_sec[main->duk_draw.mat.now.sectorno].lift)
	{
		vline_tex(main, set_point(main->duk_draw.mat.x,
				main->duk_draw.mat.cy_a, main->duk_draw.mat.cy_b), 6);
	}
	else
	{
		vline_tex(main, set_point(main->duk_draw.mat.x,
				main->duk_draw.mat.cy_a,
			main->duk_draw.mat.cy_b),
					main->duk_draw.mat.sect->num_t);
	}
}
