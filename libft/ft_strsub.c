char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;
	int		j;

	j = start;
	i = 0;
	if (result = (char*)malloc(sizeof(char*)) * (len - start) == NULL)
		return (NULL);
	while (s[j])
	{
		result[i] = s[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
