/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_deal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:06:51 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 14:55:27 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl_op.h"

int			deal_key_ter(int key, t_mlx *mlx)
{
	if (key == 15)
		g_frtlop[mlx->infos->frtl].frtl_init(mlx->frtl, mlx);
	else if (key == 46)
	{
		if (mlx->infos->mouse == 0)
			mlx->infos->mouse = 1;
		else
			mlx->infos->mouse = 0;
	}
	else if (key == 123)
		mlx->frtl->x1 -= 0.2;
	else if (key == 124)
		mlx->frtl->x1 += 0.2;
	else if (key == 126)
		mlx->frtl->y1 -= 0.2;
	else if (key == 125)
		mlx->frtl->y1 += 0.2;
	else if (key == 8)
	{
		mlx->infos->i_tab++;
		if (mlx->infos->i_tab == 11)
			mlx->infos->i_tab = 0;
		mlx->infos->color = mlx->infos->color_tab[mlx->infos->i_tab];
	}
	return (0);
}

int			deal_key_bis(int key, t_mlx *mlx)
{
	if (key == 35)
	{
		if (mlx->infos->stop_psy == 0)
			mlx->infos->stop_psy = 1;
		else
			mlx->infos->stop_psy = 0;
	}
	else if (key == 3)
	{
		if (mlx->infos->frtl == 4)
		{
			mlx->infos->frtl = 0;
			g_frtlop[mlx->infos->frtl].frtl_init(mlx->frtl, mlx);
		}
		else
		{
			mlx->infos->frtl++;
			g_frtlop[mlx->infos->frtl].frtl_init(mlx->frtl, mlx);
		}
	}
	else
		deal_key_ter(key, mlx);
	return (0);
}

int			deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
		frtl_exit(0);
	else if (key == 24 || key == 69)
	{
		mlx->frtl->zoom += 5.5;
		mlx->frtl->x1 -= 0.0001;
		mlx->frtl->y1 += 0.0001;
	}
	else if ((key == 27 || key == 78) && mlx->frtl->zoom > 2)
	{
		mlx->frtl->zoom -= 5.5;
		mlx->frtl->x1 -= 0.0001;
		mlx->frtl->y1 += 0.0001;
	}
	else if (key == 34 && mlx->frtl->i_max < 400)
		mlx->frtl->i_max++;
	else if (key == 31 && mlx->frtl->i_max > 10)
		mlx->frtl->i_max--;
	deal_key_bis(key, mlx);
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
