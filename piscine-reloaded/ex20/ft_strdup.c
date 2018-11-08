/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:31 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/08 13:53:44 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char		*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = 0;
	if ((result = (char*)malloc(sizeof(char) * ft_strlen(src))) == NULL)
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
