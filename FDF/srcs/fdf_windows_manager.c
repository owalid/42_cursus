/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_windows_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:07:08 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/20 19:39:05 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*int			deal_mouse(int key, t_mlxprint *param)
{
	if ()
	return (0);
}
*/
int			deal_key(int key, t_mlxprint *mlx)
{
	if (key == 53)
		fdf_exit(1);
	if (key == 6)
		mlx->zoom++;
	return (0);
}

void		fdf_init(int x, int y)
{
//	int			zoom;
	t_mlxprint	mlx[1];

	mlx->zoom = 50;
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, x, y, "fdf");
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x - 3, y - 3, 0xFFFFFF);
	mlx_key_hook(mlx->mlx_win, deal_key, mlx);
	mlx_new_image(mlx->mlx_ptr, 50, 50);
	mlx_loop(mlx->mlx_ptr);
}
