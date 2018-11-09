/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:16:24 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 20:26:04 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*strjoin(char const *s1, char const *s2)
{
	char		*result;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((result = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)))) == NULL)
		return (NULL);
	while (s1[j])
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
