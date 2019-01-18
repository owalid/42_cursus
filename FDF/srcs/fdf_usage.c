/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:41:28 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/16 15:48:00 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		display_usage_bis(void *mlx_ptr, void *mlx_win, int x, int y)
{
	mlx_string_put(mlx_ptr, mlx_win, x, y + 240, 0xFFFFFF,
			"relief+/relief-               R/F");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 280, 0xFFFFFF,
			"Stop move                      L");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 320, 0xFFFFFF,
			"Change view                      ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 340, 0xFFFFFF,
			"                               8");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 360, 0xFFFFFF,
			"                             4 5 6");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 380, 0xFFFFFF,
			"                               2");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 420, 0xFFFFFF,
			"Navigation                      ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 440, 0xFFFFFF,
			"                               /\\");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 460, 0xFFFFFF,
			"                            <      > ");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 480, 0xFFFFFF,
			"                               \\/");
}

void		display_usage(void *mlx_ptr, void *mlx_win)
{
	int		x;
	int		y;

	x = 20;
	y = 20;
	mlx_string_put(mlx_ptr, mlx_win, x + 40, y, 0xFFFFFF,
			"********* USAGE *********");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 40, 0xFFFFFF,
			"Exit                          ESC");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 80, 0xFFFFFF,
			"Change view                    V");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 120, 0xFFFFFF,
			"Random color                   C");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 160, 0xFFFFFF,
			"Rotation                      SPACE");
	mlx_string_put(mlx_ptr, mlx_win, x, y + 200, 0xFFFFFF,
			"Zoom/Dezoom                   +/-");
	display_usage_bis(mlx_ptr, mlx_win, x, y);
}
