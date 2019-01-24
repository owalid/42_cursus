/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:27:06 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/24 21:48:54 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_init_mand(t_frtl *frtl, t_mlx *mlx)
{
	mlx->infos->first = 0;
	frtl->x1 = -2.1;
	frtl->x2 = 2.1;
	frtl->y1 = -1.2;
	frtl->y2 = 1.2;
	frtl->tmp = 0;
	frtl->img_x = (frtl->x2 - frtl->x1) * mlx->infos->zoom;
	frtl->img_y = (frtl->y2 - frtl->y1) * mlx->infos->zoom;
}

void		frtl_init_ju(t_frtl *frtl, t_mlx *mlx)
{
	mlx->infos->first = 0;
	frtl->c_r = 0.285;
	frtl->c_i = 0.01;
	frtl->x1 = -1;
	frtl->x2 = 1;
	frtl->y1 = -1.2;
	frtl->y2 = 1.2;
	frtl->tmp = 0;
	frtl->img_x = (frtl->x2 - frtl->x1) * mlx->infos->zoom;
	frtl->img_y = (frtl->y2 - frtl->y1) * mlx->infos->zoom;
}

void		frtl_init_ship(t_frtl *frtl, t_mlx *mlx)
{
	mlx->infos->first = 0;
	frtl->x1 = -2.1;
	frtl->x2 = 2.1;
	frtl->y1 = -1.2;
	frtl->y2 = 1.2;
	frtl->img_x = (frtl->x2 - frtl->x1) * mlx->infos->zoom;
	frtl->img_y = (frtl->y2 - frtl->y1) * mlx->infos->zoom;
}
void		frtl_init(t_mlx *mlx, t_frtl *frtl)
{
	if (mlx->infos->frtl == 0)
		frtl_init_mand(frtl, mlx);
	else if (mlx->infos->frtl == 1)
		frtl_init_ju(frtl, mlx);
	else if (mlx->infos->frtl == 2)
		frtl_init_ship(frtl, mlx);
}
