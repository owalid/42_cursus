/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:58:50 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/18 18:49:00 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_init(t_infowin *infos)
{
	t_mlx	mlx[1];

	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, infos->width, infos->height, "Fractol");
	mlx->infos = infos;
	frtl_display(mlx);
	mlx_hook(mlx->mlx_win, 2, 5, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
