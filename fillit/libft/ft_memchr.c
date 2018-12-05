/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:00:07 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/09 15:37:14 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	int				i;

	str = (unsigned char*)s;
	chr = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (str[i] == chr)
			return (str + i);
		i++;
	}
	return (NULL);
}
