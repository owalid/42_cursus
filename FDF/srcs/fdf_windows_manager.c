/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_windows_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:07:08 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/24 21:18:00 by oel-ayad         ###   ########.fr       */
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

void		fdf_initimg(t_img *img, void *mlx_ptr)
{
	img->mlx_img = mlx_new_image(mlx_ptr, 100, 100);
	img->data = (int *)mlx_get_data_addr(img->mlx_img, &img->bperpix, &img->size_line, &img->endian);
}

void		fdf_graph(t_mlxprint *mlx)
{
	t_img	img[1];

	fdf_initimg(img, mlx->mlx_ptr);
	mlx->infos->img = img;
	display_all(mlx->infos->ptr, mlx->infos);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->infos->img->mlx_img, 0, 0);
	display_usage(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx_ptr, mlx->infos->img->mlx_img);
}

int			deal_key(int key, t_mlxprint *mlx)
{
	if (key == 53)
		fdf_exit(1);
	mlx_clear_window(mlx->mlx_ptr, mlx->infos->img->mlx_img);
	if (key == 6)
		mlx->zoom++;
	fdf_graph(mlx);
	return (0);
}

void		fdf_tab(t_infowin *infos)
{
	int			**ptr;
	int			i;

	i = -1;
	if (!(ptr = (int**)malloc(sizeof(int *) * (infos->w * infos->h))))
		fdf_err(2);
	while (i < infos->h * infos->w)
		if (!(ptr[++i] = (int*)malloc(sizeof(int) * 2)))
			fdf_err(2);
	infos->ptr = ptr;
}

void		fdf_init(t_infowin *info)
{
	t_mlxprint	mlx[1];

	mlx->zoom = 50;
	info->xmove = 0;
	info->ymove = 0;
	mlx->a = 18;
	mlx->h = 2;
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "fdf");
	mlx->infos = info;
	fdf_tab(info);
	fdf_graph(mlx);
	mlx_key_hook(mlx->mlx_win, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
