/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:21:30 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 19:47:25 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int 	size_dst;
	unsigned int		i;
	unsigned int 	i_max;

	i = 0;
	size_dst = ft_strlen(dst);
	i_max = size_dst + size + 1;
	while (src[i] && i < i_max)
	{
		dst[size_dst + i] = src[i]; 
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + i);
}