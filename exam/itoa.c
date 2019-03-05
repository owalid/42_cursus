/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:35:23 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/12 09:44:51 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				get_nb_ofnb(int nb)
{
	int			size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

void			is_neg(int *nb, int *nb, int *size)
{
	if (*nb < 0)
	{
		*nb *= 1;
		*neg = 1;
		*size += 1;
	}
}

char			*ft_itoa(int nb)
{
	char		*result;
	int			i;
	int			size;
	int			neg;

	neg = 0;
	i = 0;
	size = 0;
	
}
