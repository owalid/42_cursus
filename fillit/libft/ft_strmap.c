/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:42:46 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/13 16:35:04 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		len;

	if (s && f)
	{
		i = -1;
		len = ft_strlen((char *)s);
		if ((str = (char *)malloc(sizeof(*str) * len + 1)) == NULL)
			return (NULL);
		while (s[++i])
			str[i] = f(s[i]);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
