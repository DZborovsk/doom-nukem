/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:17:43 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/28 20:17:44 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	x;
	char	*src2;
	char	*dst2;

	x = 0;
	src2 = (char *)src;
	dst2 = (char *)dst;
	while (x < n)
	{
		dst2[x] = src2[x];
		if (dst2[x] == (char)c)
			return ((void *)&dst2[x + 1]);
		x++;
	}
	return (NULL);
}
