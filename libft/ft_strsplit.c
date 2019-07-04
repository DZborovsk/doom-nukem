/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:18:11 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/02 17:18:12 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_count_sign(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

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

static char				**ft_newstr(char const *s, char c, char **str)
{
	int i;
	int start;
	int i2;

	i = 0;
	i2 = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			str[i2] = ft_strsub(s, start, i - start);
			i2++;
			str[i2] = 0;
		}
	}
	str[i2] = 0;
	return (str);
}

char					**ft_strsplit(char const *s, char c)
{
	char **str;

	if (s == 0)
		return (0);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_count_sign(s, c) + 1))))
		return (0);
	ft_bzero(str, (ft_count_sign(s, c) + 1));
	return (ft_newstr(s, c, str));
}
