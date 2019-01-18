/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:31:21 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/18 18:54:01 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRTL_H
# define FRTL_H


/////////////////////////////////////////
#include <stdio.h>
////////////////////////////////////////
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WDEF		2560
# define HDEF		1440
# define ERR_USAGE	"Usage: ./fractol <fractals> [<width> <height>]\nfractals: mandelbrot, julia"
# define ERR_MALLOC "Error: malloc"
# define EXIT		"fractol: end session 😊"
# define JU			"julia"
# define MAND		"mandelbrot"

typedef struct		s_frtl
{
	double 			c_i;
	double 			c_r;
	double 			z_i;
	double			z_r;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	long long		i_max;
}					t_frtl;

typedef	struct		s_img
{
	void			*mlx_img;
	int				*data;
	int				bperpix;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_infowin
{
	int				frtl;
	int				width;
	int				height;
	int				zoom;
	t_img			*img;
}					t_infowin;


typedef struct 		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_infowin		*infos;
}					t_mlx;

/*
** 	frtl_err.c
*/
void				frtl_err(int id);
void				frtl_exit(int id);

/*
**	frtl_windows.c
*/
void				frtl_init(t_infowin *infos);


/*
**	frtl_utils.c
*/

/*
**	frtl_clean.c
*/

/*
**	frtl_display.c
*/
void				frtl_display(t_mlx *mlx);

/*
**	frtl_deal.c
*/
int					deal_key(int key, t_mlx *mlx);

#endif
