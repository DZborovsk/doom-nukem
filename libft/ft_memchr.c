/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:52:59 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/29 17:53:01 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (str2[i] == c2)
			return (&str2[i]);
		i++;
	}
	return (NULL);
}
