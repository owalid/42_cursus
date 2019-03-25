
int			pgcd(int av1, int av2)
{
	int		i;
	int		size;

	i = 2;
	size = av1;
	while (size > 0)
	{
		if (av1 % size == 0 && av2 % size == 0)
			return (size);
		size--;
	}
	return (1);
}

int			main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", pgcd(atoi(av[1]), atoi(av[2])));
	else
		printf("\n");
	return (1);
}
