/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:19:55 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/12 16:23:41 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_mov(int x, int y, t_env *e)
{
	e->sourisx = formule_scalex(e, x);
	e->sourisy = formule_scaley(e, y);
	expose_hook(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	double	tmp;
	double	tmp2;

	if (button == 2 || button == 5)
	{
		e->xscaled1 = e->xscaled1 - ((e->xscaled0 - e->xscaled1) / 2);
		e->xscaled0 = e->xscaled0 + ((e->xscaled0 - e->xscaled1) / 2);
		e->yscaled1 = e->yscaled1 - ((e->yscaled0 - e->yscaled1) / 2);
		e->yscaled0 = e->yscaled0 + ((e->yscaled0 - e->yscaled1) / 2);
	}
	else if (button == 1 || button == 4)
	{
		tmp = formule_scalex(e, x);
		tmp2 = formule_scaley(e, y);
		e->xscaled1 = tmp + ((e->xscaled1 - tmp) / 2);
		e->xscaled0 = e->xscaled0 + ((tmp - e->xscaled0) / 2);
		e->yscaled1 = tmp2 + ((e->yscaled1 - tmp2) / 2);
		e->yscaled0 = e->yscaled0 + ((tmp2 - e->yscaled0) / 2);
	}
	expose_hook(e);
	return (0);
}
