/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:30:56 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/13 21:09:37 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	int len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len - 1);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	if ((res = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	res[len + 1] = '\0';
	while (len >= 0)
	{
		res[len] = '0' + ABS(n % 10);
		n = ABS(n / 10);
		len--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
