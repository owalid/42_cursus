/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:18:58 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/13 14:38:05 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char			*result;
	size_t			i;

	i = 0;
	if ((result = (char*)malloc(sizeof(char*) * size)) == NULL)
		return (NULL);
	while (i <= size)
		result[++i] = '\0';
	return (result);
}
