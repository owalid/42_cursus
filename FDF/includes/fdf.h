/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:58 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/20 20:04:28 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


//////////////////////////////////////
#include <stdio.h>
/////////////////////////////////////

# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define BUFF_SIZE 			42
# define ERR_1				"hello"
# define ERR_2				"world"
# define ERR_3				".."
# define EXT1				"fdf: end"

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
}						t_map;

typedef struct			s_infowin
{
	int				width;
	int				height;
}						t_infowin;

typedef struct			s_mlxprint
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				zoom;
	//t_infowin		*infos;
}						t_mlxprint;

int			get_next_line(const int fd, char **line);

void		fdf_err(int id);
void		fdf_exit(int id);

t_vector	*get_map(char *file);

void		fdf_infodel(t_infowin infos);

void		fdf_init(int x, int y);
#endif
