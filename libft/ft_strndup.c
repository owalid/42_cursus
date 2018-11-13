
#include "libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char 		*str;
	size_t		i;

	i = 0;
	if((str = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	while (src[i] && i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
