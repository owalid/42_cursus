/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_mand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:50:18 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/24 19:14:41 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_iter_mand(t_frtl *frtl, t_mlx *mlx, long long x, long long y)
{
	long long	i;

	frtl->c_r = x / mlx->infos->zoom + frtl->x1;
	frtl->c_i = y / mlx->infos->zoom + frtl->y1;
	frtl->z_r = 0;
	frtl->z_i = 0;
	i = 0;
	while (frtl->z_r * frtl->z_r + frtl->z_i * frtl->z_i < 4 && i < mlx->infos->i_max)
	{
		frtl->tmp = frtl->z_r;
		frtl->z_r = frtl->z_r * frtl->z_r - frtl->z_i * frtl->z_i + frtl->c_r;
		frtl->z_i = 2 * frtl->z_i * frtl->tmp + frtl->c_i;
		i++;
	}
	if (i == mlx->infos->i_max)
		frtl_pxl(mlx, x, y, 0x000000);
	else
		frtl_pxl(mlx, x, y, mlx->infos->color * i);
}

void		frtl_dspl_mand(t_mlx *mlx)
{
	long long	x;
	long long	y;
	long long 	image_x;
	long long	image_y;

	image_x = (mlx->frtl->x2 - mlx->frtl->x1) * mlx->infos->zoom;
	image_y = (mlx->frtl->x2 - mlx->frtl->x1) * mlx->infos->zoom;
	x = 0;
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			frtl_iter_mand(mlx->frtl, mlx, x, y);
			y++;
		}
		x++;
	}
}
