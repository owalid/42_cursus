/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_deal_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:36:22 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 15:03:55 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

int			deal_mouse(int x, int y, t_mlx *mlx)
{
	x = x - mlx->infos->width / 3;
	y = y - mlx->infos->height / 3;
	if (mlx->infos->frtl == 1 && mlx->infos->mouse == 1)
	{
		mlx->frtl->c_r = (double)((double)x / (double)y);
		mlx->frtl->c_i = (double)((double)x / (double)y);
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	frtl_graph(mlx);
	return (0);
}

int			deal_scroll(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4 || button == 1)
	{
		mlx->frtl->x1 += (double)x * 0.0001;
		mlx->frtl->y1 += (double)y * 0.0001;
		mlx->frtl->zoom += 30.5;
	}
	else if (button == 5 || button == 2)
	{
		mlx->frtl->x1 -= (double)x * 0.00001;
		mlx->frtl->y1 -= (double)y * 0.00001;
		mlx->frtl->zoom -= 30.5;
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	frtl_graph(mlx);
	return (0);
}

int			deal_close(int key, t_mlx *mlx)
{
	(void)mlx;
	(void)key;
	frtl_exit(0);
	return (0);
}
