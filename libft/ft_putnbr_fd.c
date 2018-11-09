void	ft_putnbr(int n, int fd)
{
	write (fd, ft_itoa(n), ft_strlen(ft_itoa(n)));
}
