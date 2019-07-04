/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:26:24 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/28 17:26:26 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		z;

	i = 0;
	j = 0;
	z = ft_strlen(src);
	while (dst[i] && i < dstsize)
		i++;
	if (dstsize > 0)
	{
		while (src[j] && i < dstsize - 1)
			dst[i++] = src[j++];
	}
	if (j > 0)
	{
		dst[i] = '\0';
		return (z + i - j);
	}
	return (z + i);
}
