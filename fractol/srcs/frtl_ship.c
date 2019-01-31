/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:04:12 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 13:54:06 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_iter_ship(t_frtl *frtl, t_mlx *mlx, long long x, long long y)
{
	long long		i;

	frtl->c_r = x / frtl->zoom + frtl->x1;
	frtl->c_i = y / frtl->zoom + frtl->y1;
	frtl->z_r = 0;
	frtl->z_i = 0;
	i = 0;
	while (frtl->z_r * frtl->z_r + frtl->z_i * frtl->z_i < 4 && i < frtl->i_max)
	{
		frtl->tmp = frtl->z_r;
		frtl->z_r = frtl->z_r * frtl->z_r - frtl->z_i * frtl->z_i + frtl->c_r;
		frtl->z_i = 2 * fabs(frtl->tmp * frtl->z_i) + frtl->c_i;
		i++;
	}
	if (i == frtl->i_max)
		frtl_pxl(mlx, x, y, 0x000000);
	else
		frtl_pxl(mlx, x, y, mlx->infos->color * i);
}

void		frtl_dspl_ship(t_mlx *mlx)
{
	long long		x;
	long long		y;

	x = 0;
	while (x < mlx->frtl->img_x)
	{
		y = 0;
		while (y < mlx->frtl->img_y)
		{
			frtl_iter_ship(mlx->frtl, mlx, x, y);
			y++;
		}
		x++;
	}
}
