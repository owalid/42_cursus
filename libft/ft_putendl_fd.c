void		ft_putstr_fd(const char *str, int fd)
{
	write(fd, &str, ft_strlen(str));
	write(fd, '\n', 1)
}
