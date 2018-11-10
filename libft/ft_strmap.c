/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:17:31 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 20:02:14 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	i = -1;
	if ((result = (char*)malloc(sizeof(char) * ft_strlen((char*)s))) == NULL)
		return (NULL);
	while (s[++i])
		result[i] = f(s[i]);
	result[i] = '\0';
	return (result);
		
}
