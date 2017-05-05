/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 22:50:34 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/12 16:44:14 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	if (e->fractal == 1)
		fractal_julia(e);
	else if (e->fractal == 2)
		fractal_mandel(e);
	else
		fractal_ship(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF,
				"Zoom/Dezoom with Q, E");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF,
				"Move with A,W,D,S");
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF, "Change color with R");
	if (e->fractal == 1)
		mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF, "Mouse for Movement");
	return (0);
}

int		key_hook3(int keycode, t_env *e)
{
	double	tmp;
	double	tmp2;

	if (keycode == Q || keycode == E)
	{
		if (keycode == 14)
		{
			e->xscaled1 = e->xscaled1 - ((e->xscaled0 - e->xscaled1) / 2);
			e->xscaled0 = e->xscaled0 + ((e->xscaled0 - e->xscaled1) / 2);
			e->yscaled1 = e->yscaled1 - ((e->yscaled0 - e->yscaled1) / 2);
			e->yscaled0 = e->yscaled0 + ((e->yscaled0 - e->yscaled1) / 2);
		}
		else
		{
			tmp = formule_scalex(e, (W / 2));
			tmp2 = formule_scaley(e, (H / 2));
			e->xscaled1 = tmp + ((e->xscaled1 - tmp) / 2);
			e->xscaled0 = e->xscaled0 + ((tmp - e->xscaled0) / 2);
			e->yscaled1 = tmp2 + ((e->yscaled1 - tmp2) / 2);
			e->yscaled0 = e->yscaled0 + ((tmp2 - e->yscaled0) / 2);
		}
	}
	return (0);
}

int		key_hook2(int keycode, t_env *e)
{
	double	tmp;

	if (keycode == W2 || keycode == S)
	{
		tmp = (e->yscaled0 - e->yscaled1) / 8;
		e->yscaled1 += (keycode == S ? -tmp : tmp);
		e->yscaled0 += (keycode == S ? -tmp : tmp);
	}
	else if (keycode == A || keycode == D)
	{
		tmp = (e->xscaled0 - e->xscaled1) / 8;
		e->xscaled0 += (keycode == D ? -tmp : tmp);
		e->xscaled1 += (keycode == D ? -tmp : tmp);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	else if (keycode == R)
		e->theme = (e->theme == 1) ? 0 : 1;
	key_hook2(keycode, e);
	key_hook3(keycode, e);
	expose_hook(e);
	return (0);
}
