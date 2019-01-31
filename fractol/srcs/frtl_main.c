/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:40:48 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 15:24:11 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_init_infos(short mouse, short frtl, t_infowin *infos)
{
	infos->mouse = mouse;
	infos->frtl = frtl;
}

void		frtl_verif_prms(t_infowin *infos, char *prms)
{
	if (ft_strcmp(prms, MAND) == 0)
		frtl_init_infos(0, 0, infos);
	else if (ft_strcmp(prms, JU) == 0)
		frtl_init_infos(1, 1, infos);
	else if (ft_strcmp(prms, SHIP) == 0)
		frtl_init_infos(0, 2, infos);
	else if (ft_strcmp(prms, MY) == 0)
		frtl_init_infos(0, 3, infos);
	else if (ft_strcmp(prms, NEW) == 0)
		frtl_init_infos(0, 4, infos);
	if (infos->frtl == -1)
		frtl_err(1);
}

void		frtl_setwin(t_infowin *infos, int x, int y)
{
	if (x >= WDEF || y >= HDEF)
	{
		infos->width = WDEF;
		infos->height = HDEF;
	}
	else if (x >= 400 && y >= 400)
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
	t_infowin	infos[1];

	if (ac == 2 || ac == 4)
	{
		infos->frtl = -1;
		frtl_verif_prms(infos, av[1]);
		init_tabcolor(infos);
		if (ac == 4)
		{
			if (!(ft_str_is_numeric(av[2])) || !(ft_str_is_numeric(av[3])))
				frtl_err(1);
			frtl_setwin(infos, ft_atoi(av[2]), ft_atoi(av[3]));
		}
		else
			frtl_setwin(infos, WDEF, HDEF);
		wind_init(infos);
	}
	else
		frtl_err(1);
	return (0);
}
