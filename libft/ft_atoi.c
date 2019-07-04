/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:11:14 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/22 16:11:17 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int						x;
	int						neg;
	unsigned long int		res;

	x = 0;
	res = 0;
	neg = 1;
	while (ft_isspace(str[x]))
		x++;
	if (str[x] == '+')
		x++;
	else if (str[x] == '-')
	{
		neg = -1;
		x++;
	}
	while (str[x] <= '9' && '0' <= str[x])
	{
		res = (res * 10) + (str[x++] - '0');
		if (res >= 9223372036854775807 && neg == 1)
			return (-1);
		else if (res >= 9223372036854775807 && neg == -1)
			return (0);
	}
	return (res * neg);
}
