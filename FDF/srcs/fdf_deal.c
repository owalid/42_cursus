/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_deal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:53:29 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/16 14:07:52 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			deal_key_quater(int key, t_mlxprint *mlx)
{
	if (key == 86)
		mlx->yorientation += 0.01;
	else if (key == 8)
		mlx->infos->color = fdf_random_color();
	else if (key == 50)
	{
		if (mlx->egg == 0)
			mlx->egg = 1;
		else
			mlx->egg = 0;
	}
	else if (key == 91)
		mlx->xorientation += 0.01;
	else if (key == 84 && mlx->xorientation > 0.1)
		mlx->xorientation -= 0.01;
	return (0);
}

int			deal_key_ter(int key, t_mlxprint *mlx)
{
	if (key == 88 && mlx->yorientation > 0.1)
		mlx->yorientation -= 0.01;
	else if (key == 87)
	{
		if (!mlx->vpress)
		{
			mlx->yorientation = 2;
			mlx->xorientation = 2;
		}
		else
		{
			mlx->yorientation = 2.8;
			mlx->xorientation = 2.5;
		}
	}
	else if (key == 37)
	{
		if (mlx->stoplooph == 1)
			mlx->stoplooph = 0;
		else
			mlx->stoplooph = 1;
	}
	else
		deal_key_quater(key, mlx);
	return (0);
}

int			deal_key_bis(int key, t_mlxprint *mlx)
{
	if (key == 9)
	{
		if (mlx->vpress)
		{
			mlx->vpress = 0;
			mlx->xorientation = 2;
			mlx->yorientation = 2;
		}
		else
		{
			mlx->vpress = 1;
			mlx->xorientation = 2.5;
			mlx->yorientation = 2.8;
		}
	}
	else if (key == 46)
	{
		mlx->infos->xmove = 0;
		mlx->infos->ymove = 0;
	}
	else
		deal_key_ter(key, mlx);
	return (0);
}

int			deal_key(int key, t_mlxprint *mlx)
{
	if (key == 53)
		fdf_exit(1);
	else if (key == 123)
		mlx->infos->xmove++;
	else if (key == 124)
		mlx->infos->xmove--;
	else if (key == 126)
		mlx->infos->ymove++;
	else if (key == 125)
		mlx->infos->ymove--;
	else if (key == 24 || key == 69)
		mlx->zoom += 0.5;
	else if ((key == 27 || key == 78) && mlx->zoom > 2)
		mlx->zoom -= 0.5;
	else if (key == 49)
		mlx->a--;
	else if (key == 3)
		mlx->relief -= 0.15;
	else if (key == 15)
		mlx->relief += 0.15;
	else
		deal_key_bis(key, mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	fdf_graph(mlx);
	return (0);
}

int			loop_hook(t_mlxprint *mlx)
{
	if (!mlx->stoplooph)
	{
		if (mlx->yorientation > INT_MAX)
			mlx->mlx_orient_max = 1;
		if (mlx->yorientation < INT_MIN)
			mlx->mlx_orient_max = 0;
		if (mlx->mlx_orient_max == 0)
			mlx->yorientation += 0.001;
		if (mlx->mlx_orient_max == 1)
			mlx->yorientation -= 0.003;
		mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		fdf_graph(mlx);
	}
	if (mlx->egg)
	{
		mlx->infos->color = fdf_random_color();
		mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		fdf_graph(mlx);
	}
	return (0);
}
