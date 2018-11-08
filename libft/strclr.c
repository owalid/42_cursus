void		ft_strclr(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		s[i] = '\0';
}
