/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:41:18 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/01 19:41:19 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s1;

	s1 = (char *)malloc(sizeof(char) * (size + 1));
	if (s1 == NULL)
		return (NULL);
	ft_bzero(s1, size + 1);
	return (s1);
}
