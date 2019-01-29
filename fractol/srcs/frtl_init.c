/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:27:06 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/25 18:39:21 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_init_infos(short mouse, short frtl, t_infowin *infos)
{
	infos->mouse = mouse;
	infos->frtl = frtl;
}

void		frtl_init_my(t_frtl *frtl, t_mlx *mlx)
{
	frtl->img_x = mlx->infos->width - 1;
	frtl->img_y = mlx->infos->height - 1;
	frtl->c_r = 0.02;
	frtl->c_i = 0.4;
	frtl->x1 = frtl->img_x * -0.001;
	frtl->x2 = 1;
	frtl->y1 = frtl->img_y * -0.001;
	frtl->y2 = 1.2;
	frtl->tmp = 0;
	frtl->i_max = 15;
	frtl->zoom = mlx->infos->width / 5;
}

void		frtl_init_mand(t_frtl *frtl, t_mlx *mlx)
{
	frtl->img_x = mlx->infos->width - 1;
	frtl->img_y = mlx->infos->height - 1;
	frtl->x1 = frtl->img_x * -0.001 - 0.5;
	frtl->x2 = 2.1;
	frtl->y1 = frtl->img_y * -0.001;
	frtl->y2 = 1.2;
	frtl->tmp = 0;
	frtl->i_max = 30;
	frtl->zoom = mlx->infos->width / 5;
}

void		frtl_init_ju(t_frtl *frtl, t_mlx *mlx)
{
	frtl->img_x = mlx->infos->width - 1;
	frtl->img_y = mlx->infos->height - 1;
	frtl->c_r = 0.285;
	frtl->c_i = 0.01;
	frtl->x1 = frtl->img_x * -0.001;
	frtl->x2 = 1;
	frtl->y1 = frtl->img_y * -0.001;
	frtl->y2 = 1.2;
	frtl->tmp = 0;
	frtl->i_max = 100;
	frtl->zoom = mlx->infos->width / 5;

}

void		frtl_init_ship(t_frtl *frtl, t_mlx *mlx)
{
	frtl->img_x = mlx->infos->width - 1;
	frtl->img_y = mlx->infos->height - 1;
	frtl->x1 = frtl->img_x * -0.001 - 1;
	frtl->x2 = 2.1;
	frtl->y1 = frtl->img_y * -0.001 - 1;
	frtl->y2 = 1.2;
	frtl->zoom = mlx->infos->height / 4;
	frtl->i_max = 300;
}

void		frtl_init_newton(t_frtl *frtl, t_mlx *mlx)
{
	frtl->img_x = mlx->infos->width - 1;
	frtl->img_y = mlx->infos->height - 1;
	frtl->x1 = -2;
	frtl->x2 = 2;
	frtl->y1 = -2;
	frtl->y2 = 2;
	frtl->tmp = 0;
	frtl->i_max = 20;
	frtl->zoom = 100;
}

void		frtl_init(t_mlx *mlx, t_frtl *frtl)
{
	if (mlx->infos->frtl == 0)
		frtl_init_mand(frtl, mlx);
	else if (mlx->infos->frtl == 1)
		frtl_init_ju(frtl, mlx);
	else if (mlx->infos->frtl == 2)
		frtl_init_ship(frtl, mlx);
	else if (mlx->infos->frtl == 3)
		frtl_init_my(frtl, mlx);
	else if (mlx->infos->frtl == 4)
		frtl_init_newton(frtl, mlx);
}

