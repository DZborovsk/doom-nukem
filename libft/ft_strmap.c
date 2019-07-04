/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:24:18 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/02 14:24:19 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*s1;
	int			i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s1 = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (s1 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		s1[i] = (*f)(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
