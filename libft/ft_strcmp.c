/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:42:32 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/21 18:33:35 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] && s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
