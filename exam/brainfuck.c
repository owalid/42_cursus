#include <unistd.h>
#include <stdlib.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}
int		brainfuck(char *source)
{
	char 	*array;
	int		i;
	int		head;
	int		start_loop;
	int		size = 2048;

	i = 0;
	array = malloc(sizeof(char) * size);
	while (i < size)
		array[i++] = 0;
	i = 0;
	head = 0;
	start_loop = 0;
	while (source[i])
	{
		if (source[i] == '+')
			array[head]++;
		if (source[i] == '-')
			array[head]--;
		if (source[i] == '>')
			head++;
		if (source[i] == '<')
			head--;
		if (source[i] == '.')
			ft_putchar(array[head]);
		if (source[i] == '[')
			start_loop = i;
		if (source[i] == ']')
		{
			if (!(array[head] == 0))
				i = start_loop - 1;
		}
		i++;
	}
	free(array);
	return (0);
}
int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Dude, put some source to work with!\n");
		return (0);
	}
	if (brainfuck(argv[1]) == 1)
	{
		ft_putstr("Something goes wrong :(\n");
		return (1);
	}
	return (0);
}

/*

void		brainfuck(char *str)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(char) * 2048);
	while (*str)
	{
		if (*str == '>')
			ptr++;
		if (*str == '<')
		{	
			ptr--;
			str
		}
		if (*str == '+')
			(*ptr)++;
		if (*str == '-')
			(*ptr)--;
		if (*str == '[' && !*ptr)
			while (*str != ']')
				(*str)++;
		if (*str == ']' && !*ptr)
			while (*str != '[')
				(*str)--;
		if (*str ==  '.')
			write(1, ptr, 1);
		str++;
	}
}

int			main(int ac, char **av)
{
	if (ac == 2 && av[1])
		brainfuck(av[1]);
	ft_putchar('\n');
	return (0);
}*/
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putendl(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	ft_putchar('\n');
}
int	brainfuck(char *array, int *ptr, size_t n)
{
	int i = -1;
	unsigned int size = 0;
	while (++i, array[i] && size < n)
	{
		if (array[i] == '+')
			++(*ptr);
		else if (array[i] == '-')
			--(*ptr);
		else if (array[i] == '>')
		{	++ptr; ++size;		}
		else if (array[i] == '<')
		{	--ptr;	--size;		}
		else if (array[i] == '.')
			write(1, ptr, 1);
		else if (array[i] == ',')
			read(0, ptr, 1);
		else if (array[i] == '[')
			continue;
		else if (array[i] == ']' && *ptr)
		{
			int loop = 1;
			while (loop > 0)
			{
				char c = array[--i];
				if (c == '[')
					loop--;
				else if (c == ']')
					loop++;
			}
		}
		else if (array[i] != ']')
		{
			ft_putstr("Unknow symbol <");
			write(1, &array[i], 1);
			ft_putendl("> ...");
			break;
		}
	}
	return (size < n)?(0):(1);
}

int main(int argc, char **argv)
{
	int ptr[1024] = {0};

	if (argc > 1)
		return (brainfuck(argv[1], ptr, 1024));
	return (1);
}*/
