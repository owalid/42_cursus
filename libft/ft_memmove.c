/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:17:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/11 19:02:33 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (dst == src)
		return (dst);
	while (n--)
	{
		if (dst < src)
			ft_memcpy(dst, src, n);
		else
			((char *)dst)[n] = ((char *)src)[n];
		i++;
	}
	return (dst);
}
