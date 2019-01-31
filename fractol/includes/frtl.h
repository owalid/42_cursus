/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:31:21 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 15:40:55 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRTL_H
# define FRTL_H

# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# define WDEF		2560
# define HDEF		1440
# define ERR_1 "Usage: ./fractol <fractals> [<width> <height>]\n"
# define ERR_2 "fractals: mandelbrot, julia, burningship, oel-ayad, newton"
# define ERR_USAGE	ERR_1 ERR_2
# define ERR_MLX	"Error: MLX"
# define EXIT		"fractol: end session 😊"
# define JU			"julia"
# define MAND		"mandelbrot"
# define SHIP		"burningship"
# define MY			"oel-ayad"
# define NEW		"newton"
# define ITER		"Iterations: "

typedef struct		s_frtl
{
	double			c_i;
	double			c_r;
	double			z_i;
	double			z_r;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			tmp;
	double			zoom;
	long long		i_max;
	long long		img_x;
	long long		img_y;
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
	short			mouse;
	short			stop_psy;
	short			frtl;
	int				width;
	int				height;
	short			i_tab;
	unsigned int	color_tab[11];
	unsigned int	color;
	char			*iterations;
	char			*i_max_str;
	t_img			*img;
}					t_infowin;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_infowin		*infos;
	t_frtl			*frtl;
}					t_mlx;

typedef struct		s_frtlop
{
	int			id;
	char		*frtl_name;
	void		(*frtl_dspl)(t_mlx *mlx);
	void		(*frtl_init)(t_frtl *frtl, t_mlx *mlx);
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
void				frtl_graph(t_mlx *mlx);

/*
**	frtl_utils.c
*/
void				frtl_pxl(t_mlx *mlx, int x, int y, unsigned int c);
void				init_tabcolor(t_infowin *infos);
unsigned int		random_color(void);

/*
**	frtl_clean.c
*/

/*
**	frtl_mand.c
*/
void				frtl_dspl_mand(t_mlx *mlx);

/*
**	frtl_ju.c
*/
void				frtl_dspl_ju(t_mlx *mlx);

/*
**	frtl_ship.c
*/
void				frtl_dspl_ship(t_mlx *mlx);

/*
**	frtl_my.c
*/
void				frtl_dspl_my(t_mlx *mlx);

/*
**	frtl_newton.c
*/
void				frtl_dspl_new(t_mlx *mlx);

/*
**	frtl_deal.c
*/
int					deal_key(int key, t_mlx *mlx);
int					loop_hook(t_mlx *mlx);
int					deal_mouse(int x, int y, t_mlx *mlx);

/*
**	frtl_deal_mouse.c
*/
int					deal_mouse(int x, int y, t_mlx *mlx);
int					deal_scroll(int button, int x, int y, t_mlx *mlx);
int					deal_close(int key, t_mlx *mlx);

/*
**	frtl_init.c
*/
void				frtl_init_newton(t_frtl *frtl, t_mlx *mlx);
void				frtl_init_ship(t_frtl *frtl, t_mlx *mlx);
void				frtl_init_ju(t_frtl *frtl, t_mlx *mlx);
void				frtl_init_mand(t_frtl *frtl, t_mlx *mlx);
void				frtl_init_my(t_frtl *frtl, t_mlx *mlx);
/*
**	frtl_usage.c
*/
void				display_usage(t_mlx *mlx);
#endif
