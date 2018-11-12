/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:20:26 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/12 13:49:41 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *tofind, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!str[i] && !tofind[i])
		return (str);
	while (str[i] && (i + j) < n)
	{
		j = 0;
		while (str[i + j] && tofind[j] && str[i + j] == tofind[j]
				&& (i + j) < n)
			j++;
		if (!tofind[j])
			return (str + i);
		i++;
	}
	return (0);
}
