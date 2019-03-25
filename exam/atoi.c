int			ft_isblank(char c)
{
	return ((c == ' ') || (c == '\t') || (c == '\n'));
}

int			ft_atoi(char *av)
{
	int			i;
	int			neg;
	int			result;

	i = 0;
	neg = 1;
	while (ft_isblank(av[i]))
		i++;
	if (av[i] == '-')
		neg *= -1;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i] >= '0' && av[i] <= '9')
	{
		result  *= 10;
		result += av[i] - '0';
		i++;
	}
	return (result * neg);
}
