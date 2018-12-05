/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:06:59 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/13 11:42:10 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] && needle[j] == haystack[i + j])
			j++;
		if (!needle[j])
			return ((char*)haystack + i);
		i++;
	}
	return ((haystack[0] == 0 && needle[0] == 0) ? (char*)haystack : 0);
}
