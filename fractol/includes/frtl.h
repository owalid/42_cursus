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
	double			tmp;
	double			zoom;
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
	double			zoom;
	t_img			*img;
}					t_infowin;


typedef struct 		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_infowin		*infos;
	t_frtl			*frtl;
}					t_mlx;


typedef struct		s_frtlop
{
	int			id;
	void		(*frtl_dspl)(t_mlx *mlx);
}					t_frtlop;

/*
** 	frtl_err.c
*/
void				frtl_err(int id);
void				frtl_exit(int id);

/*
**	frtl_windows.c
*/
void				wind_init(t_infowin *infos);


/*
**	frtl_utils.c
*/
void				frtl_pxl(t_mlx *mlx, int x, int y, unsigned int c);

/*
**	frtl_clean.c
*/

/*
**	frtl_mand.c
*/
void		frtl_dspl_mand(t_mlx *mlx);

/*
**	frtl_ju.c
*/
void		frtl_dspl_ju(t_mlx *mlx);

/*
**	frtl_deal.c
*/
int					deal_key(int key, t_mlx *mlx);

/*
**	frtl_init.c
*/
void				frtl_init(t_mlx *mlx, t_frtl *frtl);

#endif
