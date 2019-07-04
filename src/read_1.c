/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:03:35 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:03:37 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	error_msg(char *s)
{
	ft_putstr(s);
	exit(1);
}

char	**read_file(t_sour *m)
{
	char	**result;
	char	*l;
	char	*s;

	l = NULL;
	s = NULL;
	m->fd = open(m->name, O_RDONLY);
	if ((m->fd) == -1)
		error_msg("Open file error (-1)\n");
	get_next_line_specific(m->fd, &l);
	if (!(l) || 1 > ft_strlen(l))
		error_msg("Error with get_next_line\n");
	s = ft_strdup(l);
	while (l)
	{
		free(l);
		s = join_free(s, "\n", 3);
		get_next_line_specific(m->fd, &l);
		if (l)
			s = join_free(s, l, 3);
	}
	close(m->fd);
	result = ft_strsplit(s, '\n');
	free(s);
	return (result);
}

void	doom_parser(t_sour *m, t_my_doom *dat)
{
	char	**rd;
	int		j;

	init_item_count(m);
	rd = read_file(m);
	count_all_item(m, rd);
	check_sec_ver(m, rd);
	pars_data_main(dat, m, rd);
	save_coords(dat, m, rd);
	j = 0;
	while (rd[j])
	{
		free(rd[j]);
		j++;
	}
	free(rd);
}
