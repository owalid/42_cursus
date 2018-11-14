/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:20:26 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/14 19:52:37 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char				*ft_strtrim(char const *s)
{
	int		start;
	int		size;
	char	*result;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_is_separator(s[start]))
		start++;
	size = ft_strlen(s + start) - 1;
	while (ft_is_separator(s[size + start]))
		size--;
	size++;
	if ((result = (char*)malloc(sizeof(char) * size + start + 1)) == NULL)
		return (ft_strdup(""));
	result = ft_strncat(result, s + start, size + start + 1);
	return (result);
}
