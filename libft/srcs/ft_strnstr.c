/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:20:26 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 20:30:05 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(char *str, char *tofind, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!str[i] && !tofind[i])
		return (str);
	while (str[i] && i <= n)
	{
		j = 0;
		while (str[i + j] && tofind[j] && str[i + j] == tofind[j])
			j++;
		if (!tofind[j])
			return (str + i);
		i++;
	}
	return (0);
}
