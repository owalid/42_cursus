/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 01:11:07 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/08 15:06:00 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *range;
	int i;
	int j;

	i = 0;
	if (min >= max)
		return (NULL);
	i = max - min;
	if ((range = (int*)malloc(sizeof(int) * i)) == NULL)
		return (NULL);
	i = 0;
	j = min;
	while (j < max)
	{
		range[i] = j;
		i++;
		j++;
	}
	return (range);
}
