char		*strjoin(char const *s1, char const *s2)
{
	char		*result;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (result = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	while (s1[j])
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
