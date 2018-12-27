/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:27:20 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/26 20:21:05 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	four(t_ord *line, t_infowin *infos)
{
	float	a;
	int		i;
	int		x;
	int		y;

	a = 0;
	i = 0;
	if (line->x1 > line->x2)
		ft_swap(&line->x1, &line->x2);
	i = line->x1;
	while (i < line->x2 + 1)
	{
		x = line->y1;
		y = i;
		if (y > 0 && y < infos->width && x > 0 && x < infos->height)
			infos->img->data[x * infos->width + y] = fdf_color(line->x1, line->x2, line->y1, line->y2);
		++i;
	}
}

void	three(t_ord *line, t_infowin *infos)
{
	float	a;
	int		i;
	int		x;
	int		y;

	a = 0;
	i = 0;
	if (line->y1 > line->y2)
		ft_swap(&line->y1, &line->y2);
	i = line->y1;
	while (i < line->y2 + 1)
	{
		x = i;
		y = line->x1;
		if (y > 0 && y < infos->width && x > 0 && x < infos->height)
			infos->img->data[x * infos->width + y] = fdf_color(line->x1, line->x2, line->y1, line->y2);
		++i;
	}
}

void	two(t_ord *line, t_infowin *infos)
{
	float	a;
	int		i;

	a = 0;
	i = 0;
	if (line->y1 > line->y2)
	{
		ft_swap(&line->y1, &line->y2);
		ft_swap(&line->x1, &line->x2);
	}
	a = ((float)(line->x2 - line->x1) / (line->y2 - line->y1));
	while (i < (int)line->dy + 1)
	{
		if ((line->x1 + (int)(i * a)) > 0 && (line->x1 + (int)(i * a)) <
				infos->width && (line->y1 + i) > 0 && line->y1 + i < infos->height)
			infos->img->data[(line->y1 + i) * infos->width +
				(line->x1 + (int)(i * a))] = fdf_color(line->x1, line->x2, line->y1, line->y2);
		++i;
	}
}

void		one(t_ord *line, t_infowin *infos)
{
	float	a;
	int		i;
	unsigned int b = 0xFF0000;

	a = 0;
	i = 0;
	if (line->x1 > line->x2)
	{
		ft_swap(&line->x1, &line->x2);
		ft_swap(&line->y1, &line->y2);
	}
	a = ((float)(line->y2 - line->y1) / (line->x2 - line->x1));
	while (i < (int)line->dx + 1)
	{
		if (line->x1 + i > 0 && line->x1 + i < infos->width && (line->y1
					+ (int)(i * a)) > 0 && (line->y1 + (int)(i * a)) < infos->height)
			infos->img->data[(line->y1 + (int)(i * a)) * infos->width +
				line->x1 + i] = b;
				//fdf_color(line->x1, line->x2, line->y1, line->y2);
		++i;
		b += 5;
	}
}

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
		one(line, infos);
	if (line->dx < line->dy && line->dx != 0 && line->dy != 0)
		two(line, infos);
	if (line->dx == 0)
		three(line, infos);
	if (line->dy == 0)
		four(line, infos);
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
		one(line, infos);
	if (line->dx < line->dy && line->dx != 0 && line->dy != 0)
		two(line, infos);
	if (line->dx == 0)
		three(line, infos);
	if (line->dy == 0)
		four(line, infos);
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
