/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:27:20 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/25 20:56:25 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	four(t_ord *line, t_infowin *infos)
{
	float	a;
	int		temp;
	int		i;
	int		x;
	int		y;

	a = 0;
	i = 0;
	temp = 0;
	if (line->x1 > line->x2)
	{
		temp = line->x1;
		line->x1 = line->x2;
		line->x2 = temp;
	}
	i = line->x1;
	//while (i < line->x2 + 1)
	//{
		x = line->y1;
		y = i;
		if (y > 0 && y < infos->width && x > 0 && x < infos->height)
			infos->img->data[x * infos->width + y] = fdf_color(line->x1, line->x2, line->y1, line->y2);
		++i;
	//}
}

void	three(t_ord *line, t_infowin *infos)
{
	float	a;
	int		temp;
	int		i;
	int		x;
	int		y;

	a = 0;
	i = 0;
	temp = 0;
	if (line->y1 > line->y2)
	{
		temp = line->y1;
		line->y1 = line->y2;
		line->y2 = temp;
	}
	i = line->y1;
	//while (i < line->y2 + 1)
	//{
		x = i;
		y = line->x1;
		if (y > 0 && y < infos->width && x > 0 && x < infos->height)
			infos->img->data[x * infos->width + y] = fdf_color(line->x1, line->x2, line->y1, line->y2);
		++i;
	//}
}

void	two(t_ord *line, t_infowin *infos)
{
	float	a;
	int		temp;
	int		i;

	a = 0;
	i = 0;
	temp = 0;
	if (line->y1 > line->y2)
	{
		temp = line->y1;
		line->y1 = line->y2;
		line->y2 = temp;
		temp = line->x1;
		line->x1 = line->x2;
		line->x2 = temp;
	}
	a = ((float)(line->x2 - line->x1) / (line->y2 - line->y1));
	//while (i < (int)line->dy + 1)
	//{
		if ((line->x1 + (int)(i * a)) > 0 && (line->x1 + (int)(i * a)) <
				infos->width && (line->y1 + i) > 0 && line->y1 + i < infos->height)
			infos->img->data[(line->y1 + i) * infos->width +
				(line->x1 + (int)(i * a))] = fdf_color(line->x1, line->x2, line->y1, line->y2);
		++i;
	//}
}

void		one(t_ord *line, t_infowin *infos){
	float	a;
	int		temp;
	int		i;

	a = 0;
	i = 0;
	temp = 0;
	if (line->x1 > line->x2)
	{
		temp = line->x1;
		line->x1 = line->x2;
		line->x2 = temp;
		temp = line->y1;
		line->y1 = line->y2;
		line->y2 = temp;
	}
	a = ((float)(line->y2 - line->y1) / (line->x2 - line->x1));
	/*while (i < (int)line->dx + 1)
	{*/
		if (line->x1 + i > 0 && line->x1 + i < infos->width && (line->y1
					+ (int)(i * a)) > 0 && (line->y1 + (int)(i * a)) < infos->height)
			infos->img->data[(line->y1 + (int)(i * a)) * infos->width +
				line->x1 + i] = fdf_color(line->x1, line->x2, line->y1, line->y2);
		++i;
	//}
}

void		first_line(int **ptr, t_infowin *infos)
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

void		second_line(int **ptr, t_infowin *infos)
{
	t_ord	line[1];

	line->x1 = ptr[infos->i][1];
	line->x2 = ptr[infos->i + 1][1];
	line->y1 = ptr[infos->i][0];
	line->y2 = ptr[infos->i + 1][0];
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);	
	/*if (line->dx >= line->dy && line->dx != 0 && line->dy != 0)
		one(line, infos);*/
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
			second_line(ptr, infos);
		}
		else
			x++;
		i++;
	}
	i = 0;
	while (i < infos->w * infos->h - infos->w)
	{
		infos->i = i;
		first_line(ptr, infos);
		i++;
	}
}
