/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:08:06 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/21 19:10:20 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str, int first)
{
	int i;

	i = 0;
	if (first)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_check_valid(char *nb)
{
	int i;

	i = 0;
	while (nb[i + 1])
	{
		if (nb[i] >= nb[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_max(char *nb, int n)
{
	int i;

	i = 0;
	while (nb[i])
	{
		if (nb[i] != 58 - n + i)
			return (1);
		i++;
	}
	return (0);
}

void	ft_add(char *nb, int n)
{
	int i;

	i = 0;
	nb[n - 1]++;
	while (nb[i + 1])
	{
		if (nb[n - i - 1] == ':')
		{
			nb[n - i - 1] = '0';
			nb[n - i - 2]++;
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	nb[n - 1];
	int		i;
	int		first;

	first = 0;
	i = 0;
	while (i < n)
	{
		nb[i] = '0';
		i++;
	}
	nb[i] = '\0';
	while (ft_max(nb, n))
	{
		if (ft_check_valid(nb))
		{
			ft_putstr(nb, first);
			first = 1;
		}
		ft_add(nb, n);
	}
	ft_putstr(nb, first);
}
