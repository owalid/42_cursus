
#include <stdlib.h>
#include <stdio.h>

int 	*ft_range(int start, int end)
{
	int		size;
	int		*result;
	int		i;

	i = 0;
	if (end >= start)
		size  = end - start;
	else
		size = start - end;
	if (!(result = malloc(sizeof(int) * size)))
		return (NULL);
	while (end != start)
	{
		if (end > start)
			result[i] = start++;
		else
			result[i] = end--;
		i++;
	}
	return (result);
}

int			main(int ac, char **av)
{
	int		*wsh;
	int		i;

	i = 0;
	wsh = ft_range(atoi(av[1]), atoi(av[2]));
	while (i < 50)
	{
		printf("%d\n", wsh[i]);
		i++;
	}
}
