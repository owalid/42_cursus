/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:48:03 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/13 15:05:59 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dstlen;

	i = -1;
	if (ft_strlen(dst) > n)
		return (ft_strlen(src) + n);
	while (dst[++i] && i < n)
		;
	dstlen = i;
	while (src[i - dstlen] && i < n - 1)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	if (dstlen < n)
		dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}
