/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:26:17 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/13 18:11:22 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_cal_nb_word(const char *str, char c)
{
	int		i;
	int		nb_words;
	int		in_word;

	i = 0;
	nb_words = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			in_word = 0;
		else if (in_word == 0 && str[i] != c)
		{
			in_word = 1;
			nb_words++;
		}
		i++;
	}
	return (nb_words);
}

static int			ft_calc_size_words(const char *str, int i, char c)
{
	int		size_words;

	size_words = 0;
	while (str[i++] && str[i] != c)
		size_words++;
	return (size_words + 1);
}

char				**ft_strsplit(char const *s, char c)
{
	int			nb_words;
	int			k;
	int			i;
	int			j;
	char		**result;

	nb_words = 0;
	nb_words = ft_cal_nb_word(s, c);
	if ((result = (char**)malloc(sizeof(char**)
					* (nb_words + 1))) == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < nb_words)
	{
		j = 0;
		while (s[k] == c)
			k++;
		if ((result[i] = (char*)malloc(sizeof(char*)
						* (ft_calc_size_words(s, k, c) + 1))) == NULL)
			return (NULL);
		while (s[k] != c && s[k])
			result[i][j++] = s[k++];
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}
