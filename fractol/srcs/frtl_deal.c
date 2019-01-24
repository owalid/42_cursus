/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_deal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:06:51 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/24 21:48:07 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

int			deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
		frtl_exit(0);
	else if (key == 24 || key == 69 || key == 49)
		mlx->infos->zoom += 0.5;
	else if ((key == 27 || key == 78) && mlx->infos->zoom > 2)
		mlx->infos->zoom -=  0.5;
	else if (key == 34)
		mlx->infos->i_max++;
	else if (key == 31 && mlx->infos->i_max > 10)
		mlx->infos->i_max--;
	else if (key == 3)
	{
		if (mlx->infos->frtl == 2)
			mlx->infos->frtl = 0;
		else
			mlx->infos->frtl++;
	}
	else if (key == 8)
	{
		mlx->infos->i_tab++;
		if (mlx->infos->i_tab == 11)
			mlx->infos->i_tab = 0;
		mlx->infos->color = mlx->infos->color_tab[mlx->infos->i_tab];
	}
	else if (key == 35)
	{
		if (mlx->infos->stop_psy == 0)
			mlx->infos->stop_psy = 1;
		else
			mlx->infos->stop_psy = 0;
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	frtl_graph(mlx);
	return (0);
}

int			deal_mouse(int x, int y, t_mlx *mlx)
{

	x = x - mlx->infos->width / 3;
	y = y - mlx->infos->height / 3;
	if (mlx->infos->frtl == 1 || mlx->infos->frtl == 0)
	{
		mlx->frtl->c_r = (double)((double)x / (double)y);
		mlx->frtl->c_i = (double)((double)x / (double)y);
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	frtl_graph(mlx);
	return (0);
}

int			loop_hook(t_mlx *mlx)
{
	if (mlx->infos->stop_psy == 0)
	{
		mlx->infos->color = random_color();
		mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		frtl_graph(mlx);
	}
	return (0);
}
