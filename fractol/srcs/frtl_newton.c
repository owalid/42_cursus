/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_newton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:39:53 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 15:32:09 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void			frtl_pxl_new(t_mlx *mlx, long long x, long long y, long long i)
{
	t_frtl		*frtl;

	frtl = mlx->frtl;
	if (frtl->i_max == i || frtl->z_r > 0)
		frtl_pxl(mlx, x, y, mlx->infos->color * i);
	else
		frtl_pxl(mlx, x, y, mlx->infos->color * i + 64);
}

void			frtl_iter_new(t_frtl *f, t_mlx *m, long long x, long long y)
{
	long long	i;
	double		z_rr;
	double		z_ii;
	double		save_z_r;
	double		save_z_i;

	i = -1;
	z_rr = 0;
	z_ii = 0;
	while (f->tmp > 0.0001 && ++i < f->i_max)
	{
		save_z_r = f->z_r;
		save_z_i = f->z_i;
		z_rr = f->z_r * f->z_r;
		z_ii = f->z_i * f->z_i;
		f->tmp = z_rr + z_ii * z_ii + z_ii;
		f->z_r = (2 * f->z_r * f->tmp + z_rr - z_ii) / (3 * f->tmp);
		f->z_i = (2 * f->z_i * (f->tmp - save_z_r) / (3 * f->tmp));
		f->tmp = ((f->z_r - save_z_r) * (f->z_r - save_z_r) +
				(f->z_i - save_z_i) * (f->z_i - save_z_i));
	}
	frtl_pxl_new(m, x, y, i);
}

void			frtl_dspl_new(t_mlx *mlx)
{
	long long	x;
	long long	y;
	double		save_z_r;
	double		save_z_i;

	x = 0;
	while (x < mlx->frtl->img_x)
	{
		y = 0;
		while (y < mlx->frtl->img_y)
		{
			save_z_r = mlx->frtl->z_r;
			save_z_i = mlx->frtl->z_i;
			mlx->frtl->tmp = 1;
			mlx->frtl->z_r = x / mlx->frtl->zoom + mlx->frtl->x1;
			mlx->frtl->z_i = y / mlx->frtl->zoom + mlx->frtl->y1;
			frtl_iter_new(mlx->frtl, mlx, x, y);
			y++;
		}
		x++;
	}
}
