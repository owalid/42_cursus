#include <stdlib.h>
#include <stdio.h>

int		nb_word(char *str, char c)
{
	int 	i = -1;
	int 	in_word = 0;
	int 	result = 0;

	while (str[++i])
	{
		if (str[i] == c)
			in_word = 0;
		else if (str[i] != c && in_word == 0)
		{
			in_word = 1;
			result++;
		}
	}
	return (result);
}

int		size_word_at(char *str, char c, int k)
{
	int 	result = 0;
	while (str[k] && str[k] != c)
	{
		result++;
		k++;
	}
	return (result);
}

char	**ft_strsplit(char *str, char c)
{
	int 	i;
	int 	j;
	int		k;
	char	**result;

	if (!(result = (char**)malloc(sizeof(char*) * nb_word(str, c)) + 1))
		return (NULL);
	while (str[k])
	{
		while (str[k] == c)
			k++;
		if (!(result[i] = (char*)malloc(sizeof(char) * size_word_at(str, c, k)) + 1))
			return (NULL);
		j = 0;
		while (str[k] && str[k] != c)
		{
			result[i][j] = str[k];
			k++;
			j++;
		}
		result[i++][j] = '\0';
	}
	result[i] = NULL;
	return (result);
}

void	ft_printtable(char **tab)
{
	int		i  = -1;

	while (tab[++i])
		printf("%s\n", tab[i]);
}

int		main(int ac, char **av)
{
	if (ac == 2 && *av)
	{
		char **lol = ft_strsplit(av[1], av[1][0]);
		ft_printtable(lol);
	}
	return(0);
}
