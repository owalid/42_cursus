/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:40:07 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/16 23:04:54 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int err;

	i = 0;
	err = 0;
	if (length <= 2)
		return (1);
	while (f(tab[i], tab[i + 1]) <= 0 && i < length - 1)
	{
		if (f(tab[i], tab[i + 1] < 0))
			err = 1;
		i++;
	}
	while (f(tab[i], tab[i + 1]) >= 0 && i < length - 1 && err == 0)
		i++;
	if (i == length - 1)
		return (1);
	return (0);
}
