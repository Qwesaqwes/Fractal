/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:26:53 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/12 16:18:09 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	negpos(float nb)
{
	nb = (nb < 0) ? -nb : nb;
	return (nb);
}

void	fractal_ship2(t_env *e)
{
	double	xtemp;

	while ((((e->x * e->x) + (e->y * e->y) < (1 << 16)) &&
		(e->iteration += 1) < M_ITE))
	{
		xtemp = negpos(e->x * e->x) - (e->y * e->y) +
		(formule_scalex(e, e->col));
		e->y = 2.0 * negpos(e->x * e->y) + (formule_scaley(e, e->line));
		e->x = xtemp;
	}
}

void	fractal_ship(t_env *e)
{
	double	log_zn;
	double	nu;

	e->line = -1;
	while ((e->line += 1) < e->img.height)
	{
		e->col = -1;
		while ((e->col += 1) < e->img.width)
		{
			e->x = 0.0;
			e->y = 0.0;
			e->iteration = -1.0;
			fractal_ship2(e);
			log_zn = log((e->x * e->x) + (e->y * e->y)) / 2;
			nu = log(log_zn / log(2)) / log(2);
			e->iteration = e->iteration + 1 - nu;
			e->color = palette(e->iteration, e->theme);
			pixel_put(e);
		}
	}
}
