/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:29:36 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/21 20:29:53 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int x;
	int j;
	int z;

	x = 0;
	j = 0;
	z = 0;
	while (needle[x] != '\0')
		x++;
	if (x == 0)
		return ((char *)haystack);
	while (haystack[j] != '\0')
	{
		while (needle[z] == haystack[j + z])
		{
			if (z == x - 1)
				return ((char *)haystack + j);
			z++;
		}
		z = 0;
		j++;
	}
	return (0);
}
