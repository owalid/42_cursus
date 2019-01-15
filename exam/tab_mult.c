/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:31:41 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/14 20:01:53 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int 	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void		ft_putnbr(long long nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

long long	ft_atoi(char *str)
{
	int			neg;
	int 		i;
	long long 	result;


	i = 0;
	result = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

void	ft_print_result(int nb, long long first)
{
	if (first < 10)
	{
		ft_putnbr(first);
		ft_putstr(" x ");
		ft_putnbr(nb);
		ft_putstr(" = ");
		ft_putnbr(nb * first);
		ft_putstr("\n");
		ft_print_result(nb, ++first);
	}
}


int		main(int ac, char **av)
{
	int 		nb;
	long long 	first;

	if (ac == 2)
	{
		first = 1;
		nb = ft_atoi(av[1]);
		if (nb > 0)
			ft_print_result(nb, first);
	}
	else
		ft_putstr("\n");
	return (0);
}
