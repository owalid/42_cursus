/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:40:53 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/03 09:09:25 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_res(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	if (!(a == '9' && b == '8' && c == '9' && d == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void		ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_res(a / 10 + '0', a % 10 + '0', b / 10 + '0', b % 10 + '0');
			b++;
		}
		a++;
	}
}
