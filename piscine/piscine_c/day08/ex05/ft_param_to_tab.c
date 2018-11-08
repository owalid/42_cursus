/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 23:15:07 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/14 17:46:08 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdio.h>

int						ft_strlen(char *str)
{
	int size_str;

	size_str = 0;
	while (str[++size_str])
		;
	return (size_str);
}

char					*ft_str_dup(char *src)
{
	char		*str;
	int			i;
	int			size_src;

	size_src = 0;
	i = 0;
	while (src[size_src])
		size_src++;
	if ((str = (char *)malloc(sizeof(char) * size_src)) == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par		*result;
	int						i;

	i = 0;
	result = (t_stock_par*)malloc(sizeof(t_stock_par) * ac + 1);
	if (!result)
		return (NULL);
	while (i < ac)
	{
		result[i].str = av[i];
		result[i].copy = ft_str_dup(av[i]);
		result[i].tab = ft_split_whitespaces(av[i]);
		result[i].size_param = ft_strlen(av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
