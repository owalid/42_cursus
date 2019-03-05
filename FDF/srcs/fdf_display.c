/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:27:20 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/08 13:13:34 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		vert_line(int **ptr, t_infowin *infos)
{
	t_ord	line[1];

	line->x1 = ptr[infos->i][1];
	line->x2 = ptr[infos->i + infos->w][1];
	line->y1 = ptr[infos->i][0];
	line->y2 = ptr[infos->i + infos->w][0];
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);
	if (line->dx >= line->dy && line->dx != 0 && line->dy != 0)
		first_line(line, infos);
	if (line->dx < line->dy && line->dx != 0 && line->dy != 0)
		second_line(line, infos);
	if (line->dx == 0)
		third_line(line, infos);
	if (line->dy == 0)
		fourth_line(line, infos);
}

void		hor_line(int **ptr, t_infowin *infos)
{
	t_ord	line[1];

	line->x1 = ptr[infos->i][1];
	line->x2 = ptr[infos->i + 1][1];
	line->y1 = ptr[infos->i][0];
	line->y2 = ptr[infos->i + 1][0];
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);
	if (line->dx >= line->dy && line->dx != 0 && line->dy != 0)
		first_line(line, infos);
	if (line->dx < line->dy && line->dx != 0 && line->dy != 0)
		second_line(line, infos);
	if (line->dx == 0)
		third_line(line, infos);
	if (line->dy == 0)
		fourth_line(line, infos);
}

void		display_all(int **ptr, t_infowin *infos)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	while (i < infos->w * infos->h - 1)
	{
		if ((i != (infos->w * x) - 1))
		{
			infos->i = i;
			hor_line(ptr, infos);
		}
		else
			x++;
		i++;
	}
	i = 0;
	while (i < infos->w * infos->h - infos->w)
	{
		infos->i = i;
		vert_line(ptr, infos);
		i++;
	}
}
