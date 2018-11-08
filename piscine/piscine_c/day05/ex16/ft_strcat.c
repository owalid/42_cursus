/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:06:38 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/08 18:32:11 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		size;
	char	*result;

	i = 0;
	size = 0;
	result = dest;
	while (result[i++])
		size++;
	i = 0;
	while (src[i])
	{
		result[size + i] = src[i];
		i++;
	}
	result[size + i] = '\0';
	return (result);
}
