/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:47:17 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/09 00:11:57 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strlowcase(char *str)
{
	int		i;
	char	*result;

	i = 0;
	result = str;
	while (result[i] != '\0')
	{
		if (result[i] >= 65 && result[i] <= 90)
			result[i] += 32;
		i++;
	}
	return (result);
}
