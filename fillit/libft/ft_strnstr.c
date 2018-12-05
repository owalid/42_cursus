/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:08:24 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/12 14:21:22 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t len;

	if (*needle == '\0')
		return ((char*)haystack);
	len = ft_strlen(needle);
	while (*haystack != '\0' && n-- >= len)
	{
		if (ft_memcmp(haystack, needle, len) == 0 && *haystack == *needle)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
