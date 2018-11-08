/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:35:42 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/05 23:55:31 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			nb_is_prime(int nb)
{
	int		i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb / 2)
	{
		i++;
		if (nb % i == 0)
			return (0);
	}
	return (1);
}

int			ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	if (i < 1)
		return (2);
	while (nb_is_prime(i) != 1)
		i++;
	return (i);
}
