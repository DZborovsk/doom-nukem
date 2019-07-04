/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:45:50 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/02 14:45:50 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s1 = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (s1 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		s1[i] = (*f)(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
