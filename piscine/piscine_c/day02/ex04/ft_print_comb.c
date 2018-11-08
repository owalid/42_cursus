/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 23:17:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/02 17:59:18 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_print_result(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void		ft_print_comb(void)
{
	char nums[3];

	nums[0] = '0';
	while (nums[0] <= '7')
	{
		nums[1] = nums[0] + 1;
		while (nums[1] <= '8')
		{
			nums[2] = nums[1] + 1;
			while (nums[2] <= '9')
			{
				ft_print_result(nums[0], nums[1], nums[2]);
				nums[2]++;
			}
			nums[1]++;
		}
		nums[0]++;
	}
}
