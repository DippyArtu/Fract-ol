/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 22:11:12 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 20:06:03 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_fract_type(t_fract *fractol, int type)
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
	else if (type == SHIP)
	{
		fractol->ship = init_ship();
		fractol->type = SHIP;
	}
}

void		apply_z_s(t_ship *ship, float m_re, float m_im, float intp)
{
	ship->re_max = interpolate(m_re, ship->re_max, intp);
	if (ship->re_max > 2)
		ship->re_max = 2;
	ship->re_min = interpolate(m_re, ship->re_min, intp);
	if (ship->re_min < -2)
		ship->re_min = -2;
	ship->im_max = interpolate(m_im, ship->im_max, intp);
	if (ship->im_max > ship->im_max_start)
		ship->im_max = ship->im_max_start;
	ship->im_min = interpolate(m_im, ship->im_min, intp);
	if (ship->im_min < -2)
		ship->im_min = -2;
}
