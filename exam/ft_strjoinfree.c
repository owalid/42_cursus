int			ft_strlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
;
	return (i);
}

char		*ft_strnew(int size)
{
	char		*result;

	result = malloc(sizeof(char) * size);
	result[size] = '\0';
	return (result);
}

char		*ft_strcpy(char *dest, char *src)
{
	int			i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	return (dest);
}

char		*ft_strncat(char *dest, char *src, int len)
{
	int			i;
	int			size;

	i = -1;
	size = ft_strlen(dest);
	while (src[++i] && i < len)
	{
		dest[size++] = src[i];
		size++;
	}
	result[size] = '\0';
	return (result);
}

char		*ft_strjoinfree(char *s1, char *s2, int len)
{
	char		*result;
	int			size;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = ft_strnew(size);
	ft_strcpy(s1, result);
	ft_strncat(s2, result, len);
	ft_strdel(s1);
	return (result);
}
