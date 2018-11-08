void		*ft_memalloc(size_t size)
{
	char	*result;

	if ((result = (char *)malloc(sizeof(char*) * size) == NULL)
			return (NULL);
	return (result);
}
