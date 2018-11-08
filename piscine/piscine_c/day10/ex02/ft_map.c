/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:31:16 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/17 16:01:18 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int lenght, int (*f)(int))
{
	int i;
	int *result;

	result = (int*)malloc(sizeof(int*) * lenght);
	i = 0;
	while (i < lenght)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
