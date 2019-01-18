/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:31:21 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/18 16:33:49 by oel-ayad         ###   ########.fr       */
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


typedef	struct		s_img
{
	void		*mlx_img;
	int			*data;
	int			bperpix;
	int			size_line;
	int			endian;
}					t_img;

typedef struct		s_infowin
{
	int				frtl;
	int				width;
	int				height;
	t_img			*img;
}					t_infowin;


/*
** 	frtl_err.c
*/
void				frtl_err(int id);
void				frtl_exit(int id);

/*
**	frtl_windows.c
*/

/*
**	frtl_utils.c
*/

/*
**	frtl_clean.c
*/

/*
**	frtl_deal.c
*/

#endif
