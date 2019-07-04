/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:53:28 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/21 18:29:42 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] && s2[x] && (x < n - 1))
	{
		x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
