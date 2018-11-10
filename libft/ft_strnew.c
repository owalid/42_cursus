/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:18:58 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 20:31:12 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strnew(size_t size)
{
	char 			*result;
	unsigned int	i;

	i = 0;
	if ((result = (char*)malloc(sizeof(char*) * size)) == NULL)
			return (NULL);
	while (i <= size)
		result[i] = '\0';
	return (result);
}
