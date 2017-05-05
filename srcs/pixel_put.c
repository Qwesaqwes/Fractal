/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 23:24:04 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/12 16:48:01 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_env *e)
{
	int		res;

	res = (e->col * e->img.bpp / 8) + (e->line * e->img.bpl);
	e->img.buffer[res] = (int)(e->color.r * 256) % 256;
	e->img.buffer[res + 1] = (int)(e->color.g * 256) % 256;
	e->img.buffer[res + 2] = (int)(e->color.b * 256) % 256;
}

t_color	palette(double iteration, int theme)
{
	t_color	color;

	if (theme == 0)
	{
		color.r = 0.5 + 0.5 * cos(3.0 + iteration * 0.15 + 0);
		color.g = 0.5 + 0.5 * cos(3.0 + iteration * 0.15 + 0);
		color.b = 0.5 + 0.5 * cos(3.0 + iteration * 0.15 + 0);
	}
	if (theme == 1)
	{
		color.r = 0.5 + 0.5 * cos(3.0 + iteration * 0.15 + 0);
		color.g = 0.5 + 0.5 * cos(3.0 + iteration * 0.15 + 1);
		color.b = 0.5 + 0.5 * cos(3.0 + iteration * 0.15 + 2);
	}
	return (color);
}
