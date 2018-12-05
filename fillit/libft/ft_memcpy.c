/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:45:25 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/12 12:34:42 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	const char		*sour;
	char			*dest;

	sour = src;
	dest = dst;
	i = 0;
	while (i < n)
	{
		dest[i] = sour[i];
		i++;
	}
	return (dst);
}
