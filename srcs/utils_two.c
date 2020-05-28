/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 22:11:12 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 22:11:12 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 			set_fract_type(t_fract *fractol, int type)
{
	if (type == MANDEL)
	{
		fractol->mandel = init_mandelbrot();
		fractol->type = MANDEL;
	}
	else if (type == JULIA)
	{
		fractol->julia = init_julia();
		fractol->type = JULIA;
	}
	else if (type == BUDDHA)
	{
		fractol->buddha = init_buddha();
		fractol->type = BUDDHA;
	}
	else if (type == BUDDHA_PRECALC)
		fractol->type = BUDDHA_PRECALC;
}