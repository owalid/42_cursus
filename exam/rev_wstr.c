/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:02:52 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/14 21:15:47 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int		nb_word(char *str)
{
	int 	i;
	int		nb_words;
	int		in_word;

	i = -1;
	nb_words = 0;
	in_word = 0;
	while (str[++i])
	{
		if (ft_isspace(str[i]))
			in_word = 0;
		else if (in_word == 0 && !ft_isspace(str[i]))
		{
			in_word = 1;
			nb_words++;
		}

	}
	return (nb_words);
}

int		word(char *str, int i)
{
	int		size_word;

	size_word = 0;
	while (str[++i] && !ft_isspace(str[i]))
		size_word++;
	return (size_word);
}

char	**ft_strsplit(char *s)
{
	int		i;
	int		j;
	int		k;
	char 	**result;

	if (!(result = (char**)malloc(sizeof(char*) * nb_word(s) + 1)))
		return (NULL);
	i = 0;
	k = 0;
	while (i < nb_word(s))
	{
		j = 0;
		while (ft_isspace(s[k]))
			k++;
		if (!(result[i] = (char*)malloc(sizeof(char) * word(s, k) + 1)))
			return (NULL);
		while (!ft_isspace(s[k]) && s[k])
			result[i][j++] = s[k++];
		result[i++][j] = '\0';
	}
	result[i] = NULL;
	return (result);
}

int		ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_printtab(char **s, char *str)
{
	int		i;

	i = nb_word(str) - 1;
	while (i > 0)
	{
		ft_putstr(s[i]);
		ft_putstr(" ");
		i--;
	}
		ft_putstr(s[i]);
}

int		ft_suppspace(char *str)
{
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (0);
	else 
		return (1);
}



int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_suppspace(av[1]))
			ft_printtab(ft_strsplit(av[1]), av[1]);
	}
	else
		ft_putstr("\n");
	return (0);
}
