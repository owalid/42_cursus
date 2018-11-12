/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:20:00 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/12 15:45:38 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*result;

	if (len > 0)
	{
		if ((result = (char*)malloc(sizeof(char*) * (len - start))) == NULL)
			return (NULL);
		ft_strncat(result, s + start, len);
		return (result);
	}
	result = ft_strdup("");
	return (result);
}
