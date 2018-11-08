char 	*ft_strnew(size_t size)
{
	char 	*result;
	int		i;

	i = 0;
	if ((result = (char *)malloc(sizeof(char*) * size) == NULL)
			return (NULL);
	while (i <= size)
		result[i] = '\0';
	return (result);
}
