/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:53:28 by akolinko          #+#    #+#             */
/*   Updated: 2018/07/25 16:53:29 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_valid(char c, int base)
{
	char *digits;
	char *digits2;

	digits = "0123456789abcdef";
	digits2 = "0123456789ABCDEF";
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(char *str, int str_base)
{
	int x;
	int neg;
	int res;

	x = 0;
	neg = 1;
	res = 0;
	while (ft_isspace(str[x]))
		x++;
	if (str[x] == '+')
		x++;
	else if (str[x] == '-')
	{
		neg = -1;
		x++;
	}
	while (ft_valid(str[x], str_base))
		res = (res * str_base) + (value_of(str[x++]));
	return (res * neg);
}
