/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wd_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:58:19 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/07 15:58:20 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wd_count(char const *s)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (!(*s))
			break ;
		count++;
		while (*s && !ft_isspace(*s))
			s++;
	}
	return (count);
}
