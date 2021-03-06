/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:36:41 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/16 13:11:54 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			result++;
		i++;
	}
	return (result);
}
