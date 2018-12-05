/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:27:35 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/13 11:38:58 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) + 1;
	if (s == NULL)
		return (NULL);
	while (--i >= 0 && s != NULL)
		if (s[i] == (char)c)
			return ((char*)&s[i]);
	return (NULL);
}
