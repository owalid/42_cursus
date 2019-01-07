/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:58 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/07 20:19:08 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


//////////////////////////////////////
#include <stdio.h>
#include <limits.h>
/////////////////////////////////////

# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

#define WDEF				2560;
#define HDEF				1440;
# define BUFF_SIZE 			42
# define ERR_1				"hello"
# define ERR_2				"Err: malloc, open, read"
# define ERR_3				".."
# define EXT1				"fdf: end"

typedef struct			s_ord
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	unsigned int				dy;
	unsigned int				dx;
}						t_ord;

typedef struct			s_gnl
{
	char			*str;
	struct s_gnl			*next;
}						t_gnl;

typedef struct 			s_vector
{
	long			x;
	long			y;
	long			z;
	int				color;
}						t_vector;

typedef struct			s_img
{
	void			*mlx_img;
	int				*data;
	int				bperpix;
	int				size_line;
	int				endian;

}						t_img;


typedef struct 			s_map
{
	int 			width;
	int				height;
	t_vector		*vector;
}						t_map;

typedef struct			s_infowin
{	
	unsigned int	color;
	int				xmove;
	int				ymove;
	int				w;
	int				h;
	int				i;
	int				**tab;
	int				**ptr;
	int				**ptr_save;
	int				width;
	int				height;
	t_img			*img;
}						t_infowin;

typedef struct			s_mlxprint
{
	short			vpress;
	short			mlx_orient_max;
	short			stoplooph;
	double			yorientation;
	double			xorientation;
	double			relief;
	double			zoom;
	void			*mlx_ptr;
	void			*mlx_win;
	int				a;
	int				height;
	int				h;
	t_infowin		*infos;
}						t_mlxprint;

/*
** get_next_line.c
*/
int			get_next_line(const int fd, char **line);

/*
** fdf_err.c
*/
void		fdf_err(int id);
void		fdf_exit(int id);

/*
** fdf_parser.c
*/
t_gnl		*get_map(char *file);
unsigned int fdf_color(int tag);

/*
** fdf_display.c 
*/
void		display_all(int **ptr, t_infowin *infos);

/*
** fdf_err.c
*/
void		fdf_init(t_infowin *info);
void		fdf_parser(t_gnl *map, t_infowin *infos);

/*
** utils.c
*/
t_gnl		*ft_lstgnlnew(char *str);
void		ft_lstgnlpushback(t_gnl **beginlst, char *str);
int			ft_lstgnlsize(t_gnl *lst);
#endif
