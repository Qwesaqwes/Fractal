/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:47:59 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/12 16:31:01 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_param(char *str)
{
	int		i;
	char	arg[3];

	i = -1;
	arg[0] = 'J';
	arg[1] = 'M';
	arg[2] = 'S';
	if (ft_strlen(str) > 1)
	{
		print_info();
		return (0);
	}
	while (arg[++i] != '\0')
	{
		if (arg[i] == str[0])
			return (i + 1);
	}
	print_info();
	return (0);
}

double	formule_scaley(t_env *e, int line)
{
	double	res;

	res = (double)(((e->yscaled0 - e->yscaled1) * line) /
		(double)(e->img.height)) + e->yscaled1;
	return (res);
}

double	formule_scalex(t_env *e, int col)
{
	double	res;

	res = (double)(((e->xscaled0 - e->xscaled1) * col) /
		(double)(e->img.height)) + e->xscaled1;
	return (res);
}

void	init_event(t_env *e)
{
	e->img.width = W;
	e->img.height = H;
	e->sourisx = 0.0;
	e->sourisy = 0.0;
	e->theme = 0;
	if (e->fractal == 1)
	{
		e->xscaled0 = 2.0;
		e->xscaled1 = -2.0;
		e->yscaled0 = 2.0;
		e->yscaled1 = -2.0;
	}
	if (e->fractal == 2 || e->fractal == 3)
	{
		e->xscaled0 = 1.0;
		e->xscaled1 = -2.5;
		e->yscaled0 = (e->fractal == 3) ? 1.0 : -1.0;
		e->yscaled1 = (e->fractal == 3) ? -1.0 : 1.0;
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		if (((e.fractal = check_param(&av[1][0])) == 0) ||
			!(e.mlx = mlx_init()) ||
			!(e.win = mlx_new_window(e.mlx, W, H, "Fractol")) ||
			!(e.img.img_ptr = mlx_new_image(e.mlx, W, H)) ||
			!(e.img.buffer = (unsigned char *)mlx_get_data_addr(e.img.img_ptr, \
				&e.img.bpp, &e.img.bpl, &e.img.endian)))
			return (0);
		init_event(&e);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_hook(e.win, 6, 64, mouse_mov, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	error_param(ac);
	return (0);
}
