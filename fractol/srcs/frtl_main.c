/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:40:48 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/18 18:09:04 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_verif_prms(t_infowin *infos, char *prms)
{
	if (ft_strcmp(prms, MAND) == 0)
		infos->frtl = 0;
	else if (ft_strcmp(prms, JU) == 0)
		infos->frtl = 1;
	else if (ft_strcmp(prms, BUD) == 0)
		infos->frtl = 2;
	if (infos->frtl == -1)
		frtl_err(1);
}

void		frtl_setwin(t_infowin *infos, int x, int y)
{
	if (x >= 400 && y >= 400)
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

	if (ac >= 2 && ac <= 4)
	{
		infos->frtl = -1;
		frtl_verif_prms(infos, av[1]);
		if (ac == 4)
			frtl_setwin(infos, ft_atoi(av[2]), ft_atoi(av[3]));
		else
			frtl_setwin(infos, WDEF, HDEF);
		wind_init(infos);
	}
	else
		frtl_err(1);
	return (0);
}
