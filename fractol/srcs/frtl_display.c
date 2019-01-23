/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:01:15 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/18 19:27:14 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void			frtl_pxl(t_mlx *mlx, int x, int  y, unsigned int c)
{
	int 	i;

	i = y * mlx->infos->width + x;
	mlx->infos->img->data[i] = c;
	mlx->infos->img->data[++i] = c >> 8;
	mlx->infos->img->data[++i] =  c >> 16;
}

void		frtl_iter_mand(t_frtl *frtl, t_mlx *mlx, long long x, long long y)
{
	int		i;

	i = 0;
	frtl->c_r = ((double)x) / frtl->zoom + frtl->x1;
	frtl->c_i = ((double)y) / frtl->zoom + frtl->y1;
	frtl->z_r = 0;
	frtl->z_i = 0;
	while (frtl->z_r * frtl->z_r + frtl->z_i * frtl->z_i < 4 && i < frtl->i_max)
	{
		
		frtl->tmp = frtl->z_r;
		frtl->z_r = frtl->z_r * frtl->z_r - frtl->z_i * frtl->z_i * frtl->z_i + frtl->c_r;
		frtl->z_i = 2 * frtl->tmp * frtl->z_i + frtl->c_i;
		i++;
	}
	if (i == frtl->i_max)
		mlx->infos->img->data[y * mlx->infos->width + x] = 0x000000;
	else
		frtl_pxl(mlx, x, y, 0x123456 * i);
}

void		frtl_dspl_mand(t_mlx *mlx)
{
	long long	x;
	long long	y;

	x = 0;
	while (x < mlx->infos->width)
	{
		y = 0;
		while (y < mlx->infos->height)
		{
			frtl_iter_mand(mlx->frtl, mlx, x, y);
			y++;
		}
		x++;
	}
}
