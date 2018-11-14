/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:20:26 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/14 18:54:20 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!tofind[i])
		return ((char*)str);
	while (str[i] && (i + j) < n)
	{
		j = 0;
		while (str[i + j] && tofind[j] && str[i + j] == tofind[j]
				&& (i + j) < n)
			j++;
		if (!tofind[j])
			return ((char*)(str + i));
		i++;
	}
	return (0);
}
