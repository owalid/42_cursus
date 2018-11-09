char		*ft_strmap(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	i = -1;
	if (result = (char*)malloc(sizeof(char) * ft_strlen(s)) == NULL)
		return (NULL);
	while (s[++i])
		result[i] = f(i, s[i]);
	result[i] = '\0';
	return (result);
}
