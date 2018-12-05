/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:09:52 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/05 20:21:27 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 	21
# define MAX_FD 	4096
# define TRUE		1

# define FILEERR 	"usage: ./fillit filename"
# define ERROR 		"error"

# define END 		4
# define BLOCK 		'#'
# define EMPTY 		'.'

typedef struct		s_coord
{
	int				x[5];
	int				y[5];
	struct s_coord	*next;
}					t_coord;

typedef struct		s_tetri
{
	char			**tetri;
	char			id;
	t_coord			point;
	struct s_tetri	*next;
}					t_tetri;

t_tetri				*read_file(int fd);
int					get_next_line(const int fd, char **line);
int					errors(t_tetri *lst);
int					solv_fillit(t_tetri *tetri, char **tab);

#endif
