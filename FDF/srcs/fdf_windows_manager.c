/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_windows_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:07:08 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/21 19:36:02 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*int			deal_mouse(int key, t_mlxprint *param)
{
	if ()
	return (0);
}
*/

void		display_usage(void *mlx_ptr, void *mlx_win)
{
	int 	x;
	int		y;

	x = 20;
	y = 20;
	mlx_string_put(mlx_ptr, mlx_win, x, y, 0xFFFFFF,
			"----------USAGE------------");					
	mlx_string_put(mlx_ptr, mlx_win, x, y + 40, 0xFFFFFF,
			"Exit 		 	: 		ESC  ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 80, 0xFFFFFF,
			"Change view 	:  		V   ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 120, 0xFFFFFF,
			"Change color 	: 		C    ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 160, 0xFFFFFF,
			"Zoom/Dezoom	:		+/-	");
}

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
	void 	*img;
	char	*adr;

	mlx->zoom = 50;
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, x, y, "fdf");
	while (x >= 10)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, 0xFFFFFF);
		x -= 1;
		y -= 1;
	}
	mlx_key_hook(mlx->mlx_win, deal_key, mlx);
	img = mlx_new_image(mlx->mlx_ptr, 100, 100);
	adr = mlx_get_data_addr(img, &mlx->bperpix, &mlx->size_line, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, img, 100, 100);
//	fdf_init_img();
	//mlx_new_image(mlx->mlx_ptr, 50, 50);
	display_usage(mlx->mlx_ptr, mlx->mlx_win);
	mlx_loop(mlx->mlx_ptr);
}
