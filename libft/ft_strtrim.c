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
	if (c == ' ' || c == '\t' || c == '\n' || !c)
		return (1);
	return (0);
}

char				*ft_strtrim(char const *s)
{
	int		start;
	int		size;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_is_separator(s[start]))
		start++;
	size = ft_strlen(s + start) - 1;
	while (ft_is_separator(s[size + start]) && size > 0)
		size--;
	size++;
	return (ft_strsub(s, start, size + 1));
}

/*
char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_is_separator(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s) - 1;
	while (ft_is_separator(s[len]) 
		len--;
	if (len - i == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, i, len - i + 1));
}
*/
/*
   char			*ft_strtrim(char const *s)
   {
   char	*begin;
   char	*end;
   char	*ptr;
   if (!s)
   return (NULL);

   while (ft_is_separator(*s))
   ++s;
   begin = (char*)s;
   while (*s)
   ++s;
   --s;
   while (ft_is_separator(*s))
   --s;
   end = (char*)s;
   if (end - begin == 0)
   return (ft_strdup(""));
   ptr = ft_strnew(end - begin + 1);
   ptr = ft_strncpy(ptr, begin, end - begin + 1);
   return (ptr);
   }*/
