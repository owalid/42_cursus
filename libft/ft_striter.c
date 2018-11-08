void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	i = -1;
	while (s[++i])
		f(&s[i]);
}
