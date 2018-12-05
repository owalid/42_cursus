/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:56:37 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/06 14:59:41 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	if ((result = (char *)malloc(sizeof(*s1) * (1 + i))) == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = s1[j];
		j++;
	}
	result[i] = '\0';
	return (result);
}
