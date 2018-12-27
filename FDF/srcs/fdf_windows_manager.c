/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_windows_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:07:08 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/27 20:33:06 by oel-ayad         ###   ########.fr       */
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
			"------------------------------USAGE-----------------------------------");					
	mlx_string_put(mlx_ptr, mlx_win, x, y + 40, 0xFFFFFF,
			"Exit                          ESC");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 80, 0xFFFFFF,
			"Change view                    V");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 120, 0xFFFFFF,
			"Change color                   C");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 160, 0xFFFFFF,
			"Rotation                      SPACE");	
	mlx_string_put(mlx_ptr, mlx_win, x, y + 200, 0xFFFFFF,
			"Zoom/Dezoom                   +/-");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 240, 0xFFFFFF,
			"relief+/relief-               R/F");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 280, 0xFFFFFF,
			"change view                      ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 280, 0xFFFFFF,
			"                              8");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 300, 0xFFFFFF,
			"                            4 5 6");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 320, 0xFFFFFF,
			"                              2");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 340, 0xFFFFFF,
			"Navigation                      ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 360, 0xFFFFFF,
			"                               /\\");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 380, 0xFFFFFF,
			"                            <      > ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 400, 0xFFFFFF,
			"                               \\/");
}

void		fdf_initimg(t_infowin *infos, t_img *img, void *mlx_ptr)
{
	img->mlx_img = mlx_new_image(mlx_ptr, infos->width, infos->height);
	img->data = (int *)mlx_get_data_addr(img->mlx_img, &img->bperpix, &img->size_line, &img->endian);
}

int		**to_isometric(t_mlxprint *mlx, int a, int zoom, int height)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < mlx->infos->h)
	{
		j = 0;
		while (j < mlx->infos->w)
		{
			mlx->infos->ptr_save[k][0] = mlx->infos->tab[i][j];
			mlx->infos->ptr[k][0] = ((i * cos(a) * zoom + j * cos(a + mlx->xorientation) * zoom
						+ mlx->infos->tab[i][j] * mlx->relief * cos(a - mlx->xorientation) * zoom / 30 * height) +
					(mlx->infos->height / 4)) 
				+ mlx->infos->ymove *  50;
			mlx->infos->ptr[k][1] = ((i * sin(a) * zoom + j * sin(a + mlx->yorientation) * zoom
						+ mlx->infos->tab[i][j] * mlx->relief * sin(a - mlx->yorientation) * zoom / 30 * height) +
					(mlx->infos->width / 2.25)) 
				+ mlx->infos->xmove * 50;
			++j;
			++k;
		}
		++i;
	}
	return (mlx->infos->ptr);
}

void		fdf_graph(t_mlxprint *mlx)
{
	t_img	img[1];

	fdf_initimg(mlx->infos, img, mlx->mlx_ptr);
	mlx->infos->img = img;
	to_isometric(mlx, mlx->a, mlx->zoom, mlx->h);
	display_all(mlx->infos->ptr, mlx->infos);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->infos->img->mlx_img, 0, 0);
	display_usage(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx_ptr, mlx->infos->img->mlx_img);
}

int			deal_key(int key, t_mlxprint *mlx)
{
	if (key == 53)
		fdf_exit(1);
	if (key == 123)
		mlx->infos->xmove++;
	if (key == 124)
		mlx->infos->xmove--;
	if (key == 126)
		mlx->infos->ymove++;
	if (key == 125)
		mlx->infos->ymove--;
	if (key == 24)
		mlx->zoom++;
	if (key == 27 && mlx->zoom > 2)
		mlx->zoom--;
	if (key == 49)
		mlx->a--;
	if (key == 3)
		mlx->relief -= 0.15;
	if (key == 15)
		mlx->relief += 0.15;
	if (key == 9)
	{
		if (mlx->xorientation == 2.5 && mlx->yorientation == 2.8)
		{
			mlx->xorientation = 2;
			mlx->yorientation = 2;
		}
		else 
		{
			mlx->xorientation = 2.5;
			mlx->yorientation = 2.8;
		}
	}
	if (key == 46)
	{
		mlx->infos->xmove = 0;
		mlx->infos->ymove = 0;
	}
	if (key == 91)
		mlx->xorientation += 0.01;
	if (key == 84 && mlx->xorientation > 0.1)
		mlx->xorientation -= 0.01;
	if (key == 86)
		mlx->yorientation += 0.01;
	if (key == 88 && mlx->yorientation > 0.1)
		mlx->yorientation -= 0.01;
	if (key == 87)
	{
		mlx->yorientation = 2;
		mlx->xorientation = 2;
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	fdf_graph(mlx);
	return (0);
}

void		fdf_tab(t_infowin *infos)
{
	int 		**ptr_save;
	int			**ptr;
	int			i;

	i = -1;
	if (!(ptr = (int**)malloc(sizeof(int *) * (infos->w * infos->h))) ||
				!(ptr_save = (int**)malloc(sizeof(int*) * (infos->w * infos->h))))
		fdf_err(2);
	while (i < infos->h * infos->w)
	{
		if (!(ptr[i] = (int*)malloc(sizeof(int) * 2)) || !(ptr_save[i] = (int*)malloc(sizeof(int))))
			i++;
}
			fdf_err(2);
	infos->ptr = ptr;
	infos->ptr_save = ptr_save;
}

void		fdf_init(t_infowin *info)
{
	t_mlxprint	mlx[1];

	mlx->relief = 1;
	mlx->zoom = 50;
	info->xmove = 0;
	info->ymove = 0;
	mlx->yorientation = 2;
	mlx->xorientation = 2;
	mlx->a = -1;
	mlx->h = 2;
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, info->width, info->height, "fdf");
	mlx->infos = info;
	fdf_tab(info);
	fdf_graph(mlx);
	mlx_hook(mlx->mlx_win, 2, 5, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
