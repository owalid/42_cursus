/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:47:22 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/18 18:38:29 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_op.h"

int			ft_usage(int nb1, int nb2)
{
	return (nb1 + nb2);
}

int			check_error(int argc, char **argv)
{
	int result;
	int i;

	i = 0;
	result = 0;
	if (argc != 4)
		return (0);
	if ((ft_strcmp(argv[2], "/") == 0) && (ft_atoi(argv[3]) == 0))
	{
		ft_putstr(ERR_DIV);
		return (0);
	}
	if ((ft_strcmp(argv[2], "%") == 0) && ft_atoi(argv[3]) == 0)
	{
		ft_putstr(ERR_MOD);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (check_error(argc, argv) == 0)
		return (0);
	while (ft_strcmp(g_optab[i].op, ""))
	{
		if (ft_strcmp(g_optab[i].op, argv[2]) == 0)
		{
			ft_putnbr(g_optab[i].put_f(ft_atoi(argv[1]), ft_atoi(argv[3])));
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	ft_putnbr(0);
	ft_putchar('\n');
	return (0);
}
