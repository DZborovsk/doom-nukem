/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:00:27 by akolinko          #+#    #+#             */
/*   Updated: 2018/04/02 14:00:29 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *s1;

	s1 = (char*)malloc(sizeof(char) * size);
	if (s1 == NULL)
		return (NULL);
	ft_bzero(s1, size);
	return (s1);
}
