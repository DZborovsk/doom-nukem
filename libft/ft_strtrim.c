/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:54:38 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/02 15:54:45 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int max;
	int len;

	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] != '\0') && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	max = ft_strlen(s);
	while ((i < max)
			&& (s[max - 1] == ' ' || s[max - 1] == '\n' || s[max - 1] == '\t'))
		max--;
	if (i == max)
		return (ft_strnew(1));
	len = max - i;
	return (ft_strsub(s, i, len));
}
