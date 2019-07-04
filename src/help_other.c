/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:13:32 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:14:38 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	import_object(t_my_doom *d)
{
	int q;
	int i;
	int j;
	int color;

	color = 0x115509;
	d->flag == 1 ? color = 0x792315 : 1;
	q = SDL_GetTicks();
	if (q - d->time < 500)
	{
		i = -1;
		while (i < HEIGHT)
		{
			j = -1;
			while (j < WIDTH)
			{
				d->duk_draw.dr_img[i][j] += color;
				++j;
			}
			++i;
		}
	}
	else
		d->flag = 0;
}

void	set_pxl_col(t_my_doom *main, int texture, int x, int y)
{
	int c;

	c = main->duk_draw.txs[texture][main->duk_draw.mat.u
		* 128 + main->duk_draw.mat.v];
	if (c != 0x000000)
	{
		if (main->duk_sec[main->duk_draw.mat.now.sectorno].light == 0)
		{
			main->duk_draw.dr_img[y][x] = pixel_bright(c, 0.025
			* main->duk_draw.mat.z);
		}
		else
		{
			main->duk_draw.dr_img[y][x] = c;
		}
	}
}

void	ft_help_math(t_duk_br calcul, t_my_doom *main,
		int color)
{
	while (calcul.x != calcul.en_dr || calcul.y != calcul.y_end)
	{
		calcul.f += (calcul.b * calcul.b_sn);
		if (calcul.f > 0)
		{
			calcul.f -= (calcul.a * calcul.a_sn);
			calcul.x -= calcul.b_sn;
		}
		calcul.y += calcul.a_sn;
		if (calcul.y > 0 && calcul.y < HEIGHT &&
		calcul.x > 0 && calcul.x < WIDTH)
			main->duk_draw.dr_img[calcul.y][calcul.x] = color;
	}
}

void	doom_lift_check(t_my_doom *main, unsigned int i)
{
	int		lift_check;
	int		up;
	int		falling;
	float	speed;

	lift_check = 4;
	falling = 3;
	speed = 0.6;
	up = 2;
	while (i < main->duk_draw.sec_num)
	{
		if (main->duk_sec[i].lift == lift_check)
		{
			main->duk_sec[i].floor += speed;
			if (main->duk_sec[i].floor >= main->duk_sec[i].ceil - 19)
			{
				main->duk_sec[i].floor = main->duk_sec[i].ceil - 19;
				main->duk_sec[i].lift = up;
				main->duk_gm.p_lif--;
			}
		}
		else if (main->duk_sec[i].lift == falling)
			help_check_lift(main, i, speed);
		i++;
	}
}

int		load_png_doom(t_my_doom *main, int tex_arr_num, char *path)
{
	SDL_Surface		*surf;
	int				i;
	int				j;
	unsigned int	*pixels;

	ft_check_img(main);
	surf = IMG_Load(path);
	if (!surf)
	{
		ft_putendl(IMG_GetError());
		return (-1);
	}
	pixels = (unsigned int *)surf->pixels;
	j = -1;
	while (++j < 128)
	{
		i = -1;
		while (++i < 128)
			main->duk_draw.txs[tex_arr_num][i + (128 * j)] =
		pixels[(j * surf->w) + i];
	}
	SDL_FreeSurface(surf);
	return (1);
}
