/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:39:43 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/05 01:23:13 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
