/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:39:39 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/21 19:39:54 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copi;
	int		len;
	int		x;

	len = 0;
	x = 0;
	while (s1[len] != '\0')
		len++;
	copi = malloc(sizeof(*s1) * (len + 1));
	if (copi == NULL)
		return (NULL);
	while (s1[x] != '\0')
	{
		copi[x] = s1[x];
		x++;
	}
	copi[x] = '\0';
	return (copi);
}
