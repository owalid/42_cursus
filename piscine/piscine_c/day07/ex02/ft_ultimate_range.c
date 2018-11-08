/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 01:26:14 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/13 16:45:43 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*result;
	int		j;
	int		i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if ((result = (int*)malloc(sizeof(int*) * (max - min))) == NULL)
	{
		*range = NULL;
		return (0);
	}
	j = min;
	while (j < max)
	{
		result[i] = j;
		i++;
		j++;
	}
	*range = result;
	return (i);
}
