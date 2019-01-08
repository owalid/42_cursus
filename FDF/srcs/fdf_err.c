/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:42 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/08 21:13:36 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_err(int id)
{
	if (id == 1)
		ft_putendl(ERR_1);
	if (id == 2)
		ft_putendl(ERR_2);
	if (id == 3)
		ft_putendl(ERR_3);
	exit(id);
}

void		fdf_exit(int id, t_mlxprint *mlx)
{
	if (id == 1)
	{
		fdf_del_mlx(mlx);
		ft_putendl(EXT1);
	}
	exit(0);
}
