/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:41:02 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/16 19:18:48 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		verif_map(t_gnl *map)
{
	char		**split;
	t_gnl		*tmp_map;
	size_t		tmp;

	tmp_map = map;
	split = ft_strsplit(tmp_map->str, ' ');
	tmp = ft_tab_len(split);
	tmp_map = tmp_map->next;
	ft_del_tab(&split);
	while (tmp_map)
	{
		split = ft_strsplit(tmp_map->str, ' ');
		if (tmp != ft_tab_len(split))
			fdf_err(6);
		tmp_map = tmp_map->next;
		ft_del_tab(&split);
	}
	fdf_del_map(&tmp_map);
}

void		fdf_verif_ext(char *file)
{
	int i;

	i = ft_strlen(file) - 4;
	if (i <= 0 || ft_strcmp(file + i, ".fdf"))
		fdf_err(1);
}

void		fdf_setwin(t_infowin *infos, int x, int y)
{
	if (x >= 300 && y >= 300)
	{
		infos->width = x;
		infos->height = y;
	}
	else
	{
		infos->width = WDEF;
		infos->height = HDEF;
	}
}

int			main(int ac, char **av)
{
	t_gnl		*map;
	t_infowin	infos[1];

	if (ac > 1 && ac < 5)
	{
		fdf_verif_ext(av[1]);
		if (ac == 4)
			fdf_setwin(infos, ft_atoi(av[2]), ft_atoi(av[3]));
		else
			fdf_setwin(infos, WDEF, HDEF);
		map = get_map(av[1]);
		verif_map(map);
		fdf_parser(map, infos);
		fdf_init(infos);
		fdf_del_info(infos);
	}
	else
		fdf_err(1);
	return (0);
}
