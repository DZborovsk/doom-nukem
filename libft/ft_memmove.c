/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:30:39 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/29 15:30:40 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dst2;
	char *src2;

	dst2 = (char *)dst;
	src2 = (char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	if (dst > src)
	{
		while (len--)
			dst2[len] = src2[len];
	}
	return (dst2);
}
