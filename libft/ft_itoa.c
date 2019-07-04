/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:49:53 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/02 18:49:55 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	tmp;

	i = ft_numlen(n);
	tmp = n;
	if (n < 0)
	{
		tmp = n * -1;
		i++;
	}
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	str[--i] = tmp % 10 + '0';
	while (tmp /= 10)
		str[--i] = tmp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
