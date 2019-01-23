/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_deal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:06:51 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/18 18:01:03 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

int			deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
		frtl_exit(0);
	if (key == 24 || key == 69 || key == 49)
		mlx->infos->zoom += 0.5;
	if ((key == 27 || key == 78) && mlx->infos->zoom > 2)
		mlx->infos->zoom -=  0.5;
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	wind_init(mlx->infos);
	return (0);
}
