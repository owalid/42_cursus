/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:53:53 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/08 13:06:36 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fourth_line(t_ord *line, t_infowin *infos)
{
	float	a;
	int		neg;
	int		i;
	int		x;
	int		y;

	a = 0;
	i = 0;
	neg = 1;
	if (line->x1 > line->x2)
	{
		neg = -1;
		ft_swap(&line->x1, &line->x2);
	}
	i = line->x1;
	while (i < line->x2 + 1)
	{
		x = line->y1;
		y = i;
		if (y > 0 && y < infos->width && x > 0 && x < infos->height)
			infos->img->data[x * infos->width + y] = infos->color;
		i++;
	}
}

void		third_line(t_ord *line, t_infowin *infos)
{
	int		neg;
	float	a;
	int		i;
	int		x;
	int		y;

	a = 0;
	i = 0;
	neg = 1;
	if (line->y1 > line->y2)
	{
		neg = -1;
		ft_swap(&line->y1, &line->y2);
	}
	i = line->y1;
	while (i < line->y2 + 1)
	{
		x = i;
		y = line->x1;
		if (y > 0 && y < infos->width && x > 0 && x < infos->height)
			infos->img->data[x * infos->width + y] = infos->color;
		i++;
	}
}

void		second_line(t_ord *line, t_infowin *infos)
{
	int		neg;
	float	a;
	int		i;

	neg = 1;
	a = 0;
	i = 0;
	if (line->y1 > line->y2)
	{
		neg = -1;
		ft_swap(&line->y1, &line->y2);
		ft_swap(&line->x1, &line->x2);
	}
	a = ((float)(line->x2 - line->x1) / (line->y2 - line->y1));
	while (i < (int)line->dy + 1)
	{
		if ((line->x1 + (int)(i * a)) > 0 && (line->x1 + (int)(i * a)) <
				infos->width && (line->y1 + i) > 0 &&
				line->y1 + i < infos->height)
			infos->img->data[(line->y1 + i) * infos->width +
				(line->x1 + (int)(i * a))] = infos->color;
		i++;
	}
}

void		first_line(t_ord *line, t_infowin *infos)
{
	int		neg;
	float	a;
	int		i;

	neg = 1;
	a = 0;
	i = 0;
	if (line->x1 > line->x2)
	{
		neg = -1;
		ft_swap(&line->x1, &line->x2);
		ft_swap(&line->y1, &line->y2);
	}
	a = ((float)(line->y2 - line->y1) / (line->x2 - line->x1));
	while (i < (int)line->dx + 1)
	{
		if (line->x1 + i > 0 && line->x1 + i < infos->width && (line->y1
					+ (int)(i * a)) > 0 &&
				(line->y1 + (int)(i * a)) < infos->height)
			infos->img->data[(line->y1 + (int)(i * a)) * infos->width +
				line->x1 + i] = infos->color;
		i++;
	}
}
