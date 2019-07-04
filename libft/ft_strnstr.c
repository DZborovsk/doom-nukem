/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:18:06 by akolinko          #+#    #+#             */
/*   Updated: 2018/03/28 15:18:09 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	char		*s1;
	char		*s2;
	int			len;

	if (!*needle)
		return ((char*)haystack);
	s1 = (char *)haystack;
	s2 = (char *)needle;
	len = ft_strlen(s2);
	i = 0;
	while (s1[i] != '\0' && (i + len) <= n)
	{
		if (ft_strncmp(haystack + i, needle, len) == 0)
		{
			return (s1 + i);
		}
		i++;
	}
	return (NULL);
}
