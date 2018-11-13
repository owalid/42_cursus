#include "libft.h"

char		*ft_strlowcase(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!(ft_islower(str[i])))
			str[i] = ft_tolower(str[i]);
	return(str);
}
