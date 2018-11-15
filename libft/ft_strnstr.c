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

	i = 0;
	if (!tofind[i] || !n)
		return ((char*)str);
	i = ft_strlen(tofind);
	while (*str &&  n-- >= i)
	{
		if (!ft_strncmp(str, tofind, i))
			return ((char*)str);
		str++;
	}
	return (NULL);
}
