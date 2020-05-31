/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:52:09 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 15:07:08 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		interpolate(float start, float end, float interp)
{
	return (start + ((end - start) * interp));
}

void		apply_zoom(t_mandel *man, float m_re, float m_im, float interp)
{
	man->re_max = interpolate(m_re, man->re_max, interp);
	if (man->re_max > 2)
		man->re_max = 2;
	man->re_min = interpolate(m_re, man->re_min, interp);
	if (man->re_min < -2)
		man->re_min = -2;
	man->im_max = interpolate(m_im, man->im_max, interp);
	if (man->im_max > man->im_max_start)
		man->im_max = man->im_max_start;
	man->im_min = interpolate(m_im, man->im_min, interp);
	if (man->im_min < -2)
		man->im_min = -2;
}

void		zoom_in(t_fract *fract)
{
	float		*zoom;
	float 		interp;

	zoom = &fract->pos->zoom;
	*zoom /= (float)Z_FACTOR;
	interp = (float)(1 / Z_FACTOR);
	if (fract->type == MANDEL)
		apply_zoom(fract->mandel, fract->mouse->re, fract->mouse->im, interp);
	else if (fract->type == SHIP)
		apply_z_s(fract->ship, fract->mouse->re, fract->mouse->im, interp);
	if (fract->iter_c++ == 3)
	{
		if (fract->pos->max_iter == K_MAX)
			fract->iter_c = 0;
		else
			fract->pos->max_iter++;
		fract->iter_c = 0;
	}
}

void		zoom_out(t_fract *fract)
{
	float	*zoom;
	float 	interp;

	zoom = &fract->pos->zoom;
	*zoom *= (float)Z_FACTOR;
	interp = (float)(1 * Z_FACTOR);
	if (fract->type == MANDEL)
		apply_zoom(fract->mandel, fract->mouse->re, fract->mouse->im, interp);
	else if (fract->type == SHIP)
		apply_z_s(fract->ship, fract->mouse->re, fract->mouse->im, interp);
	if (fract->iter_c++ == 3)
	{
		if (fract->pos->max_iter == K_START)
			fract->iter_c = 0;
		else
			fract->pos->max_iter--;
		fract->iter_c = 0;
	}
}

void		shift_control(int key, t_fract *fract)
{
	if (key == 124)
		fract->pos->shift_x += (float)0.02 * (float)fract->pos->zoom;
	else if (key == 123)
		fract->pos->shift_x -= (float)0.02 * (float)fract->pos->zoom;
	else if (key == 125)
		fract->pos->shift_y -= (float)0.02 * (float)fract->pos->zoom;
	else if (key == 126)
		fract->pos->shift_y += (float)0.02 * (float)fract->pos->zoom;
}
