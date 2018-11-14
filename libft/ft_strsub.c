/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:20:00 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/14 18:43:04 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, size_t start, size_t len)
{
	char		*result;

	if (len > 0 && start < len)
	{
		if ((result = (char*)malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		result = ft_strncat(result, s + start, len + 1);
		return (result);
	}
	result = ft_strdup("");
	return (result);
}
