/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:21:30 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/11 17:07:00 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int		size_dst;
	unsigned int		i;
	unsigned int		i_max;

	i = 0;
	size_dst = ft_strlen(dst);
	i_max = size_dst + size;
	if (size < size_dst)
		return (ft_strlen(src) + size);
	while (src[i] && i < (i_max - 1))
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	while (src[i])
		i++;
	return (size_dst + i);
}
