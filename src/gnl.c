/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:47:10 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:47:53 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

char	*join_free(char *str1, char *str2, int j)
{
	size_t	i;
	char	*res;
	int		z;

	z = -1;
	if (!str1 || !str2)
		return (0);
	i = ft_strlen(str1) + ft_strlen(str2);
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	i = -1;
	while (str1[++i])
		res[i] = str1[i];
	while (str2[++z])
		res[i + z] = str2[z];
	if (j == 3 || j == 1)
		free(str1);
	return (res);
}

char	*first_line(char **fdf_ile, int fd)
{
	int		q;
	char	first_buf[BUFF_SIZE + 1];

	while ((q = read(fd, first_buf, BUFF_SIZE)) > 0)
	{
		first_buf[q] = '\0';
		if (!*fdf_ile)
			*fdf_ile = ft_strdup(first_buf);
		else
			*fdf_ile = join_free(*fdf_ile, first_buf, 3);
	}
	return (fdf_ile[fd]);
}

int		get_next_line_specific(int const fd, char **line)
{
	int			res;
	static char	*fdf_ile[4864];

	res = 0;
	if (!line || (fd < 0 || fd >= 4864) || (read(fd, fdf_ile[fd], 0) < 0))
		return (-1);
	if (!fdf_ile[fd])
		first_line(&fdf_ile[fd], fd);
	if (fdf_ile[fd])
		res = change_line(&fdf_ile[fd], line);
	if (res != 0 || fdf_ile[fd] == NULL || fdf_ile[fd][0] == '\0')
	{
		if (!res && *line)
			*line = NULL;
		return (res);
	}
	*line = fdf_ile[fd];
	fdf_ile[fd] = NULL;
	return (1);
}
