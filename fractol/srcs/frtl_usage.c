/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:14:36 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 14:24:10 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl_op.h"

void		display_usage_bis(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 380, 0xFFFFFF,
			"                      /\\");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 400, 0xFFFFFF,
			"                   <      > ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 420, 0xFFFFFF,
			"                      \\/");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 500, 0xFFFFFF,
			mlx->infos->iterations);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, mlx->infos->width - 150,
			mlx->infos->height - 150, 0xFFFFFF,
				g_frtlop[mlx->infos->frtl].frtl_name);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 360, 0xFFFFFF,
			"Navigation                      ");
}

void		display_usage(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 20;
	y = 20;
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x + 40, y, 0xFFFFFF,
			"********* USAGE ********");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 40, 0xFFFFFF,
			"Exit                  ESC");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 80, 0xFFFFFF,
			"Change fractal         F");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 120, 0xFFFFFF,
			"Zoom/Dezoom            +/-");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 160, 0xFFFFFF,
			"Change color           C");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 200, 0xFFFFFF,
			"Increment iteration    I/O");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 240, 0xFFFFFF,
			"Psychedelic mode       P");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 280, 0xFFFFFF,
			"Reset                  R");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 320, 0xFFFFFF,
			"Mouse                  M");
	display_usage_bis(mlx, x, y);
}
