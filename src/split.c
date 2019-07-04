/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:34:58 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:39:13 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_free_int(int **free_int)
{
	if (free_int)
	{
		free(*free_int);
		*free_int = NULL;
	}
}

static size_t	ft_int_count(char const *str, char del)
{
	int	j;
	int i;

	i = -1;
	j = 0;
	while (str[++i] != '\0')
	{
		if (str[i] != del && (str[i + 1] == del || str[i + 1] == '\0'))
			j++;
	}
	return (j);
}

int				*ft_intsplit(char const *str, char c)
{
	size_t	i;
	size_t	start_int;
	size_t	end_int;
	int		*r;
	int		j;

	i = -1;
	j = 1;
	if (!str || !(r = (int *)malloc((ft_int_count(str, c) + 1) * sizeof(int))))
		return (NULL);
	while (str[++i] != '\0')
	{
		if (str[i] != c)
		{
			start_int = i;
			end_int = i;
			while (str[end_int] != '\0' && str[end_int] != c)
				end_int++;
			r[j++] = ft_atoi(&str[start_int]);
			i = end_int - 1;
		}
	}
	r[0] = j - 1;
	return (r);
}
