/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:07:01 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:07:02 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	wall_height(t_sour *m, char **str, int length)
{
	int a;
	int max;

	a = 0;
	if (length == 11)
	{
		max = 7;
	}
	else
	{
		max = 8;
	}
	while (max > ++a)
	{
		if (is_num(str[a]) == 1
			|| (2 < a && (m->size_vert <= ft_atoi(str[a])
			|| 0 > ft_atoi(str[a]))))
		{
			error_msg("vertical error in map\n");
		}
	}
}

void	wall_check(t_sour *m, char **s, int length)
{
	int a;

	if (length == 11)
	{
		a = 6;
	}
	else
	{
		a = 7;
	}
	while (++a != length)
	{
		if (s[a][2] == '\0' && '-' == s[a][0] && '1' == s[a][1])
		{
			continue ;
		}
		if (is_num(s[a]) == 1 || m->sec_sou <=
		ft_atoi(s[a]) || 0 > ft_atoi(s[a]))
		{
			error_msg("error wall detected\n");
		}
	}
}

void	sector_check(t_sour *m, char **s)
{
	int length;

	length = arr_len(s);
	if (length != 13
		&& length != 11)
	{
		error_msg("error line sec\n");
	}
	if (ft_atoi(s[1]) > ft_atoi(s[2])
		|| (ft_atoi(s[2]) - ft_atoi(s[1])) > 100)
	{
		error_msg("error ceil\n");
	}
	wall_height(m, s, length);
	wall_check(m, s, length);
}

void	vertical_tex(char **s)
{
	int a;

	a = 1;
	while (s[a])
	{
		if (1 == is_num(s[a]))
		{
			error_msg("vertical_tex error\n");
		}
		a++;
	}
}

void	check_sec_ver(t_sour *m, char **r)
{
	int		y;
	char	**s;

	y = 0;
	while (r[y])
	{
		s = ft_strsplit(r[y], ' ');
		if (!(s[0]))
		{
			y++;
			continue ;
		}
		if (!(ft_strcmp(s[0], "sector")))
			sector_check(m, s);
		if (!(ft_strcmp(s[0], "vertex")))
			vertical_tex(s);
		m->sou_i = 0;
		while (s[m->sou_i])
		{
			free(s[m->sou_i]);
			m->sou_i++;
		}
		free(s);
		y++;
	}
}
