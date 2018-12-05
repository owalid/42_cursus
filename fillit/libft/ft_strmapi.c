/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:11:40 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/13 16:35:51 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	int				len;

	if (s && f)
	{
		i = -1;
		len = ft_strlen((char *)s);
		if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
			return (NULL);
		while (s[++i])
			str[i] = f(i, s[i]);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
