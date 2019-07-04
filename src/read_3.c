/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:01:59 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 18:02:01 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		norm_other(t_sour *main, char **str)
{
	if (ft_strcmp(str[0], "lift") == 0 || ft_strcmp(str[0], "door_sector") == 0
		|| ft_strcmp(str[0], "end") == 0)
	{
		if (is_num(str[1]) == 0 && ft_atoi(str[1]) >= 0
			&& main->sec_sou > ft_atoi(str[1]) && arr_len(str) == 2)
			return (0);
		else
		{
			error_msg("error end/door/lift\n");
		}
	}
	else if (!(ft_strcmp(str[0], "enemy")))
	{
		if (is_num(str[1]) == 0 && is_num(str[2]) == 0
			&& is_num(str[3]) == 0 && ft_atoi(str[3]) >= 0
			&& main->sec_sou > ft_atoi(str[3]) && arr_len(str) == 4)
			return (0);
	}
	else if (!(ft_strcmp(str[0], "texture_sector")))
	{
		if (ft_atoi(str[1]) >= 0 && ft_atoi(str[1]) < main->sec_sou &&
		ft_atoi(str[2]) >= 0 && arr_len(str) == 3 && ft_atoi(str[2]) <= 6)
			return (0);
	}
	return (1);
}

void	check_id_name(t_sour *m, char **s)
{
	if (ft_strcmp(s[0], "vertex") == 0)
	{
		m->size_vert += arr_len(s) - 2;
		m->ver_num++;
	}
	else if (!(ft_strcmp(s[0], "sector")))
		m->sec_sou = m->sec_sou + 1;
	else if (!(ft_strcmp(s[0], "player")) && !(error_check(m, s)))
		m->pl_sou = m->pl_sou + 1;
	else if (!(ft_strcmp(s[0], "key")) && !(error_check(m, s)))
		m->kyl_sou = m->kyl_sou + 1;
	else if (!(ft_strcmp(s[0], "ammunition")) && !(error_check(m, s)))
		m->amm_sou = m->amm_sou + 1;
	else if (!(ft_strcmp(s[0], "door_sector")) && !(norm_other(m, s)))
		m->do_sou = m->do_sou + 1;
	else if (!(ft_strcmp(s[0], "enemy")) && !(norm_other(m, s)))
		m->nem_sou = m->nem_sou + 1;
	else if (!(ft_strcmp(s[0], "end")) && !(norm_other(m, s)))
		m->en_sou = m->en_sou + 1;
	else if (!(ft_strcmp(s[0], "lift")) && !(norm_other(m, s)))
		m->lft_sou = m->lft_sou + 1;
	else if (!(ft_strcmp(s[0], "texture_sector")) && !(norm_other(m, s)))
		m->xt_sou = m->xt_sou + 1;
	else
		error_msg("error in map\n");
}

void	check_v_sec(t_sour *m)
{
	if ((m->sec_sou * 5) < m->size_vert)
	{
		error_msg("error vertex_sector\n");
	}
	if (m->sec_sou != m->xt_sou)
	{
		error_msg("sector not texture_sector\n");
	}
	if (m->en_sou != 1 || m->pl_sou != 1)
	{
		error_msg("error end or start\n");
	}
}

void	count_all_item(t_sour *m, char **r)
{
	char	**string;
	int		q;
	int		i;

	q = 0;
	while (r[q])
	{
		string = ft_strsplit(r[q], ' ');
		if (string[0] == NULL)
		{
			continue ;
		}
		check_id_name(m, string);
		i = 0;
		while (string[i])
		{
			free(string[i]);
			i++;
		}
		free(string);
		q++;
	}
	check_v_sec(m);
}

void	init_item_count(t_sour *data)
{
	data->do_sou = 0;
	data->lft_sou = 0;
	data->size_vert = 0;
	data->ver_num = 0;
	data->sec_sou = 0;
	data->en_sou = 0;
	data->nem_sou = 0;
	data->pl_sou = 0;
	data->kyl_sou = 0;
	data->amm_sou = 0;
	data->xt_sou = 0;
}
