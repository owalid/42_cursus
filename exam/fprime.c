#include <stdio.h>
#include <stdlib.h>

void	fprime(long nb)
{
	unsigned int 	i;

	if (nb == 1)
		printf("1");
	else
	{
		i = 1;
		while (nb > 1)
		{
			i++;
			if (nb % i == 0)
			{
				printf("%d", i);
				nb /= i;
				if (nb > 1)
					printf("*");
				i--;
			}
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
