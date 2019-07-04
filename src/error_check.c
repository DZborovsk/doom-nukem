/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:00:58 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:01:00 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		arr_len(char **s)
{
	int index;

	index = 0;
	while (s[index])
	{
		index++;
	}
	return (index);
}

int		is_num(char *s)
{
	int index;

	index = 0;
	while (s[index])
	{
		if (s[index] == '-')
		{
			index++;
			continue ;
		}
		if ('9' < s[index] || '0' > s[index])
		{
			return (1);
		}
		if (index > 3)
		{
			return (1);
		}
		index++;
	}
	return (0);
}

int		error_check(t_sour *m, char **s)
{
	int i;

	i = 0;
	if (arr_len(s) == 5 && (!(ft_strcmp(s[0], "ammunition"))
		|| !(ft_strcmp(s[0], "player")) || !(ft_strcmp(s[0], "key"))))
	{
		while (s[++i])
		{
			if (is_num(s[i]) == 1)
			{
				error_msg("bad num\n");
			}
		}
		if (0 > ft_atoi(s[4]) || m->sec_sou <= ft_atoi(s[4]))
		{
			error_msg("bad sector\n");
		}
		if ((ft_atoi(s[1]) < 0 || 3 < ft_atoi(s[1]))
			&& (!(ft_strcmp(s[0], "key"))))
			error_msg("bad type\n");
		return (0);
	}
	else
		error_msg("error_check_func\n");
	return (1);
}
