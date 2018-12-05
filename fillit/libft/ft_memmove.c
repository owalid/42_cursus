/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:59:57 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/13 20:31:44 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = -1;
	if (dst > src)
		while ((int)(--len) >= 0)
			((char *)dst)[len] = ((char *)src)[len];
	else
		while (++i < len)
			((char*)dst)[i] = ((char*)src)[i];
	return (dst);
}
