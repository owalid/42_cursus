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

void		frtl_display(t_mlx *mlx)
{
	long long	img_x;
	long long	img_y;
	long long	x;
	long long	y;
	long long	i;
	double		tmp;
	t_frtl 		frtl[1];
	unsigned int color[51];
	unsigned int start;

	start = 0x0000FF;
	frtl->i_max = 50;
	frtl->x1 = -2.1;
	frtl->x2 = 0.6;
	frtl->y1 = -1.2;
	frtl->y2 = 1.50;
	mlx->infos->zoom = 100;
	x = 0;
	img_x = (frtl->x2 - frtl->x1) * mlx->infos->zoom;
	img_y = (frtl->y2 - frtl->y1) * mlx->infos->zoom;
	i = 0;
	while (i < frtl->i_max)
	{
		color[i] = start;
		start += 0x00000F;
		i++;
	}
	i = 0;
	while (x < img_x)
	{
		y = 0;
		while (y < img_y)
		{
			frtl->c_r = x / mlx->infos->zoom + frtl->x1;
			frtl->c_i = y / mlx->infos->zoom + frtl->y1;
			frtl->z_r = 0;
			frtl->z_i = 0;
			i = 0;
			tmp = frtl->z_r;
			frtl->z_r = pow(frtl->z_r, 2) - pow(frtl->z_i, 2) + frtl->c_r;
			frtl->z_i = 2 * tmp * frtl->z_i + frtl->c_i;
			while (pow(frtl->z_r, 2) + pow(frtl->z_i, 2) < 4
					&& i < frtl->i_max)
			{
			i++;
				tmp = frtl->z_r;
				frtl->z_r = pow(frtl->z_r, 2) - pow(frtl->z_i, 2) + frtl->c_r;
				frtl->z_i = 2 * tmp * frtl->z_i + frtl->c_i;
			}
			if (i == frtl->i_max)
				mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, 0x000000);
			else
				mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, color[i]);
			y++;
		}
		x++;
	}
}
