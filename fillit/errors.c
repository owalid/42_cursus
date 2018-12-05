/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:09:58 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/05 20:20:20 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		nb_piece(char **piece)
{
	int nb_blocks;
	int nb_empty;
	int i;
	int j;

	nb_blocks = 0;
	nb_empty = 0;
	i = -1;
	while (piece[++i])
	{
		j = -1;
		if (ft_strlen(piece[i]) != END)
			return (0);
		while (piece[i][++j])
			if (piece[i][j] != BLOCK && piece[i][j] != EMPTY)
				return (0);
		nb_blocks += ft_strccnt(piece[i], BLOCK);
		nb_empty += ft_strccnt(piece[i], EMPTY);
	}
	if ((nb_blocks != END && nb_empty != END * END - END) || i != END)
		return (0);
	return (1);
}

static int		piece_integrity(char **piece)
{
	int	x;
	int y;
	int count;

	count = 0;
	y = -1;
	while (piece[++y])
	{
		x = -1;
		while (piece[y][++x])
		{
			if (piece[y][x] == BLOCK)
			{
				if (y < (END - 1) && piece[y + 1][x] == BLOCK)
					count++;
				if (x < (END - 1) && piece[y][x + 1] == BLOCK)
					count++;
				if (y && piece[y - 1][x] == BLOCK)
					count++;
				if (x && piece[y][x - 1] == BLOCK)
					count++;
			}
		}
	}
	return ((count == 6 || count == 8) ? 1 : 0);
}

int		errors(t_tetri *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (!nb_piece(lst->tetri) || !piece_integrity(lst->tetri))
			return (0);
		lst = lst->next;
	}
	return (1);
}
