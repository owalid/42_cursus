/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:41:02 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/10 16:17:17 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		fdf_parser(map, infos);
		fdf_init(infos);
		fdf_del_info(infos);
	}
	else
		fdf_err(1);
	return (0);
}
