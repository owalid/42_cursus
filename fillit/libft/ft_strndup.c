/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:05:38 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/23 19:14:32 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *fresh;

	if (ft_strlen(s1) > n || !s1)
		return (NULL);
	if (!(fresh = (char*)malloc(sizeof(*fresh) * n + 1)))
		return (NULL);
	fresh[n] = '\0';
	while (n--)
		fresh[n] = s1[n];
	return (fresh);
}
