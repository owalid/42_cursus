/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:20:00 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 20:10:22 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;
	int		j;

	j = start;
	i = 0;
	if ((result = (char*)malloc(sizeof(char*) * (len - start))) == NULL)
		return (NULL);
	while (s[j])
	{
		result[i] = s[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
