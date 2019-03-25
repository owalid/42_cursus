#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		nb_word(char *str, char c)
{
	int		i = 0;
	int		in_word = 0;
	int		result = 0;

	while (str[i])
	{
		if  (str[i] != c)
			in_word = 0;
		else if  (str[i] == c && in_word == 0)
		{
			result++;
			in_word = 1;
		}
		i++;
	}
	return (result);
}

int		nb_wordat(char *str, int i, char c)
{
	int		size_word;

	size_word = 0;
	while (str[i++] && str[i] != c)
		size_word++;
	return (size_word);
}

char		**ft_split(char *str, char c)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	char	**result;

	result = (char**)malloc(sizeof(char*) * nb_word(str, c) + 1);
	while (str[k])
	{
		j = 0;
		while (str[k] == c)
			k++;
		result[i] = (char*)malloc(sizeof(char) * nb_wordat(str, k, c) + 1);
		while (str[k] && str[k] != c)
		{
			result[i][j] = str[k];
			j++;
			k++;
		}
		result[i][j++] = '\0';
		i++;
	}
	result[i++] = NULL;
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
		char **lol = ft_split(av[1], av[1][0]);
		ft_printtable(lol);
	}
	return(0);
}
