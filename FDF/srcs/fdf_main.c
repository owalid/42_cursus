/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:41:02 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/20 22:24:46 by oel-ayad         ###   ########.fr       */
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
	int i;
	t_vector	*map;
	t_infowin	infos[1];

	if (ac > 1 && ac < 5)
	{
		fdf_verif_ext(av[1]);
		if (ac == 4)
			fdf_setwin(infos,  av[2], av[3]);
			// modifier les valeurs par default de la fenetre
		else
		{
			infos->width = 1280;
			infos->height = 720;
		}
		fdf_init(infos->width, infos->height);
		map = get_map(av[1]);
		i = 0;
		/*while(map)
		{
			ft_putnbr(map[i].x);
			ft_putchar('\n');
			ft_putnbr(map[i].y);
			ft_putchar('\n');
			ft_putnbr(map[i].z);
			ft_putchar('\n');
			i++;
		}*/
		//ft_parse(map, infos);
	//	ft_strdel(map);
	//	ft_stctdel(infos);
	}
	fdf_err(1);
	return (0);
}
