/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_budbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:58:34 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/24 17:16:09 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_iter_budbrot(t_frtl *frtl, t_mlx *mlx, long long x, long long y)
{
	long long	i;

	i = 0;
	frtl->c_r = x / mlx->infos->zoom + frtl->x1;
	frtl->c_i = y / mlx->infos->zoom + frtl->y2; 
	frtl->z_r = 0;
	frtl->z_i = 0;	
	while (frtl->z_r * frtl->z_r + frtl->z_i * frtl->z_i > 4 && i < mlx->infos->i_max)
	{
		frtl->tmp = frtl->z_r;
		frtl->z_r = frtl->z_r * frtl->z_r - frtl->z_i * frtl->z_i + frtl->c_r;
		frtl->z_i = 2 * frtl->z_i * frtl->tmp + frtl->c_i;
		i++;
	}
	if (i == mlx->infos->i_max)
		frtl_pxl(mlx, x, y, 0x000000);
	else
		frtl_pxl(mlx, x, y, 0x123456 * i);
}

void		frtl_dspl_budbrot(t_mlx *mlx)
{
	t_frtl		*frtl;
	long long	x;
	long long	y;

	x = 0;
	frtl = mlx->frtl;
	while (x < mlx->infos->height)
	{
		y = 0;
		while (y < mlx->infos->width)
		{
			frtl_iter_budbrot(frtl, mlx, x, y);
			y++;
		}
		x++;
	}
}
