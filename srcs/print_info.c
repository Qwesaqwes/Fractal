/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:43:05 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/12 16:06:16 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_info(void)
{
	ft_putchar('\n');
	ft_putstr("     --->PARAMETERS<---\n");
	ft_putchar('\n');
	ft_putstr(">> J:               Julia\n");
	ft_putstr(">> M:               Mandelbrot\n");
	ft_putstr(">> S:               Burning Ship\n");
	ft_putchar('\n');
	ft_putchar('\n');
}

void	error_param(int ac)
{
	if (ac > 2)
	{
		ft_putstr(">> Too many parameter, plis tap only 1 parameter <<\n");
		print_info();
	}
	if (ac < 2)
	{
		ft_putstr(">> Too few parameter, plis tap only 1 parameter <<\n");
		print_info();
	}
}
