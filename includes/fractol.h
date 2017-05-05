/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:51:13 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/12 16:40:51 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "fcntl.h"
# include "math.h"

# define W 1000
# define H 1000
# define M_ITE 100
# define ESC 53
# define W2 13
# define S 1
# define A 0
# define D 2
# define Q 12
# define E 14
# define R 15

typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

typedef struct			s_img
{
	int					width;
	int					height;
	int					bpp;
	int					bpl;
	int					endian;
	unsigned char		*buffer;
	void				*img_ptr;
}						t_img;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_color				color;
	int					fractal;
	int					line;
	int					col;
	int					theme;
	double				iteration;
	double				x;
	double				y;
	double				xscaled0;
	double				xscaled1;
	double				yscaled0;
	double				yscaled1;
	double				sourisx;
	double				sourisy;
}						t_env;

void					print_info(void);
void					fractal_mandel(t_env *e);
void					fractal_julia(t_env *e);
void					fractal_ship(t_env *e);
void					pixel_put(t_env *e);
void					error_param(int ac);
int						expose_hook(t_env *e);
int						key_hook(int keycode, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
int						mouse_mov(int x, int y, t_env *e);
double					formule_scaley(t_env *e, int line);
double					formule_scalex(t_env *e, int col);
t_color					palette(double iteration, int theme);

#endif
