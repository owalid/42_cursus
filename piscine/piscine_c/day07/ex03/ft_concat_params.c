/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:23:01 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/13 12:18:34 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		result;

	result = 0;
	while (*str != '\0')
	{
		str++;
		result++;
	}
	return (result);
}

char		*ft_concat_params(int argc, char **argv)
{
	char	*result;
	int		size_max;
	int		i;
	int		j;
	int		k;

	size_max = 0;
	i = 1;
	while (argv[++i])
		size_max += ft_strlen(argv[i]) + 1;
	result = (char*)malloc(sizeof(char) * size_max);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			result[k++] = argv[i][j++];
		if (i < argc - 1)
			result[k++] = '\n';
		i++;
	}
	result[k] = '\0';
	return (result);
}
