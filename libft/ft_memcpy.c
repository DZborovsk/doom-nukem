/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:37:31 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/28 19:37:33 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		((char *)dst)[x] = ((char *)src)[x];
		x++;
	}
	return (dst);
}