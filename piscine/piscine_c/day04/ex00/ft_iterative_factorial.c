/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:46:40 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/05 19:32:20 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_iterative_factorial(int nb)
{
	int result;
	int i;

	result = 1;
	i = 1;
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}
