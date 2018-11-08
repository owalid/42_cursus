/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 00:33:58 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/05 01:30:59 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_sort_integer_table(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
