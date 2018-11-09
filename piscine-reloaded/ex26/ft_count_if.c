/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count-if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:31:29 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/08 13:57:26 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		i;
	int		result;

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