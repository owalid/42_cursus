/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:27:20 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/21 19:13:25 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		one(t_line *line, t_infowin infos){
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
				line->x1 + i] = 0xFFFFFF;
		++i;
	}
}

void		fdf_display_line(t_ord *ord)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ord->dy = ord->y1 - ord->y2;
	ord->dx = ord->x1 - ord->x2;
	while (x >= ord->x1 || x <= ord->x2)
	{
		fdf_draw_line(x, y);
		x++;
	}
}

void		first_line(int **ptr, t_infos *infos)
{
	t_line	line[1];

	line->x1 = ptr[infos->i][1];
	line->x2 = ptr[infos->i + infos->w][1];
	line->y1 = ptr[infos->i][0];
	line->y2 = ptr[infos->i + infos->w][0];
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);
	if (line->dx >= line->dy && line->dx != 0 && line->dy != 0)
		one(line, infos);
}


void		display_all(int **ptr, t_infowin *infos)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < infos->w * infos->h - 1)
	{
		if ((i != (infos->w * x) - 1))
		{
			infos->i = i;
			first_line(ptr, infos);
		}
		else
			x++;
		i++;
	}
	i = 0;
	while (i < infos->w * infos->h - infos->w)
	{
		infos->i = i;
		secondline(ptr, infos);
		i++;
	}
}
