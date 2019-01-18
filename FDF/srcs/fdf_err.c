/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:42 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/16 16:51:52 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_err(int id)
{
	if (id == 1)
		ft_putendl(ERR_USAGE);
	if (id == 2)
		ft_putendl(ERR_FILE);
	if (id == 3)
		ft_putendl(ERR_MALLOC);
	if (id == 4)
		ft_putendl(ERR_READ);
	if (id == 5)
		ft_putendl(ERR_OPEN);
	if (id == 6)
		ft_putendl(ERR_INFILE);
	exit(id);
}

void		fdf_exit(int id)
{
	if (id == 1)
	{
		ft_putendl(EXT1);
		exit(0);
	}
	exit(id);
}
