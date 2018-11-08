/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:32:23 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/04 21:23:36 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_iterative_power(int nb, int power)
{
	int		result;

	result = 1;
	if (power < 0)
	{
		return (0);
	}
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
