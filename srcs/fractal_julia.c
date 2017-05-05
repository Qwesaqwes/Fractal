/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 21:42:44 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/12 16:12:53 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_julia2(t_env *e)
{
	double	res;
	double	x0;
	double	y0;
	double	xtemp;

	x0 = formule_scalex(e, e->col);
	y0 = formule_scaley(e, e->line);
	res = exp(-sqrt(x0 * x0 + y0 * y0));
	while ((e->iteration += 1) < M_ITE && (x0 + y0) < (1 << 16))
	{
		xtemp = x0;
		x0 = x0 * x0 - y0 * y0 + e->sourisx;
		y0 = 2.0 * xtemp * y0 + e->sourisy;
		res += exp(-sqrt(x0 * x0 + y0 * y0));
	}
	e->iteration = res;
}

void	fractal_julia(t_env *e)
{
	e->line = -1;
	while ((e->line += 1) < e->img.height)
	{
		e->col = -1;
		while ((e->col += 1) < e->img.width)
		{
			e->iteration = -1.0;
			fractal_julia2(e);
			e->color = palette(e->iteration, e->theme);
			pixel_put(e);
		}
	}
}
