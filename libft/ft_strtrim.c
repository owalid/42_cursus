int             ft_is_separator(char c)
{
        if (c == ' ' || c == '\t' || c == '\n')
                return (1);
        return (0);
}
int			ft_calc_blank(char *str)
{
	int		i;
	int		nb_blank

	nb_blank = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_separator(str[i]))
			nb_blank++;
		i++;
	}
	return (nb_blank);
}
char		*no_blank(char *s)
{
	int		i;
	int		j;
	char	*result;

	i = -1;
	j = 0;
	if (result = (char*)malloc(sizeof(char) * (ft_strlen(s) - ft_calc_blank(s))) == NULL)
		return (NULL);
	while (str[j])
	{
		if (ft_is_separator(str[j]) == 0)
			result[++i] = str[j];
		j++;
	}
	result[i] = '\0';
	return (result);
}

