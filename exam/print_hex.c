/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:18:46 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/14 19:31:19 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i =-1;
	while (str[++i])
		;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

long long		ft_atoi(char *str)
{
	int 		i;
	long long	result;
	int			neg;

	i = 0;
	neg = 1;
	result = 0;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

int		nb_of_nb(long long nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

long long	second_nb(long long a)
{
	return (a % 10);
}

void	ft_itoa_hex(long long nb)
{
	char	result[1024];
	int 	size;

	result[1023] = '\0';
	size = nb_of_nb(nb);
	while (size--)
	{
		if (nb % 16 > 9)
			result[size] = 97 + second_nb(nb % 16);
		else
			result[size] = nb % 16 + '0';
		nb /= 16;
	}
	ft_putstr(result);
}

int		main(int ac, char **av)
{
	long long	tmp;

	if (ac == 2)
	{
			tmp = ft_atoi(av[1]);
			if (tmp > 0)
				ft_itoa_hex(tmp);
			if (tmp == 0)
			{
				if (av[1][0] == '0')
					ft_putstr("0");
			}
	}
	ft_putstr("\n");
	return (0);
}
