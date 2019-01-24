/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:14:36 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/24 20:12:03 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		display_usage(t_mlx *mlx)
{
	int		x;
	int		y;
	char	*iteration;

	x = 20;
	y = 20;
	iteration = ft_strjoin(ITER, ft_itoa(mlx->infos->i_max));
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
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, x, y + 310, 0xFFFFFF,
		iteration);
}
