/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:41:02 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/25 20:06:47 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_verif_ext(char *file)
{
	int i;

	i = ft_strlen(file) - 4;
	if (i <= 0 || ft_strcmp(file + i, ".fdf"))
		fdf_err(2);
}
void	fdf_setwin(t_infowin *infos, char *x, char *y)
{
	infos->width = ft_atoi(x);
	infos->height = ft_atoi(y);
}

int 	main(int ac, char **av)
{
	t_gnl		*map;
	t_infowin	infos[1];

	if (ac > 1 && ac < 5)
	{
		fdf_verif_ext(av[1]);
		if (ac == 4)
			fdf_setwin(infos,  av[2], av[3]);
			// modifier les valeurs par default de la fenetre
		else
		{
			infos->width = 2560;
			infos->height = 1440;
		}
		map = get_map(av[1]);
		fdf_parser(map, infos);
		fdf_init(infos);

	}
	return (0);
}
