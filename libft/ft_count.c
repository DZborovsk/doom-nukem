/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:25:57 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/11 11:26:56 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count(char const *s, char c)
{
	size_t		count;
	size_t		i;
	size_t		len;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (i == 0 && s[i] != c)
			count++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
