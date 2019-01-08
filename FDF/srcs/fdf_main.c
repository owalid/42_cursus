/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:41:02 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/08 21:10:57 by oel-ayad         ###   ########.fr       */
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

void		fdf_setwin(t_infowin *infos, char *x, char *y)
{
	int 	xfinal;
	int 	yfinal;

	xfinal = ft_atoi(x);
	yfinal = ft_atoi(y);
	if (xfinal >= 300 && yfinal >= 300)
	{
		infos->width = xfinal;
		infos->height = yfinal;
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
			fdf_setwin(infos, av[2], av[3]);
		else
			fdf_setwin(infos, "", "");
		map = get_map(av[1]);
		fdf_parser(map, infos);
		fdf_init(infos);
	}
	else
		fdf_err(1);
	return (0);
}
