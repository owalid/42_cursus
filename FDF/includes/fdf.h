#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define BUFF_SIZE 			42

typedef struct 			s_vector
{
	long			x;
	long			y;
	long			z;
	int				color;
}						t_vector;

typedef struct 			s_map
{
	int 			width;
	int				height;
	t_vector		*vector;
}						t_map

typedef struct			s_infowin
{
	int				width;
	int				height;
}						t_infowin

int		get_next_line(const int fd, char **line);

#endif
