/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_quarters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:48:37 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/24 16:50:05 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

void	quart_four(t_line *line, int colorid, t_infowin *infos)
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
	while (i < line->x2 + 1)
	{
		x = line->y1;
		y = i;
		if (y > 0 && y < infos->width && x > 0 && x < infos->height)
			infos->mlx->data[x * infos->width + y] = color_picker(colorid);
		++i;
	}
}

void	quart_three(t_line *line, int colorid, t_infowin *infos)
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
	while (i < line->y2 + 1)
	{
		x = i;
		y = line->x1;
		if (y > 0 && y < infos->width && x > 0 && x < infos->height)
			infos->mlx->data[x * infos->width + y] = color_picker(colorid);
		++i;
	}
}

void	quart_two(t_line *line, int colorid, t_infowin *infos)
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
	while (i < (int)line->dy + 1)
	{
		if ((line->x1 + (int)(i * a)) > 0 && (line->x1 + (int)(i * a)) <
			infos->width && (line->y1 + i) > 0 && line->y1 + i < infos->height)
			infos->mlx->data[(line->y1 + i) * infos->width +
				(line->x1 + (int)(i * a))] = color_picker(colorid);
		++i;
	}
}

void	quart_one(t_line *line, int colorid, t_infowin *infos)
{
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
	while (i < (int)line->dx + 1)
	{
		if (line->x1 + i > 0 && line->x1 + i < infos->width && (line->y1
			+ (int)(i * a)) > 0 && (line->y1 + (int)(i * a)) < infos->height)
			infos->mlx->data[(line->y1 + (int)(i * a)) * infos->width +
				line->x1 + i] = color_picker(colorid);
		++i;
	}
}
