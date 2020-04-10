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
	float	*zoom;
	float 	interp;

	zoom = &fract->mandel->pos->zoom;
	*zoom /= (float)Z_FACTOR;
	interp = (float)(1 / Z_FACTOR);
	apply_zoom(fract->mandel, fract->mouse->Re, fract->mouse->Im, interp);
	if (fract->iter_c++ == 3)
	{
		if (fract->max_iter == K_MAX)
			fract->iter_c = 0;
		else
			fract->max_iter++;
		fract->iter_c = 0;
	}
}

void		zoom_out(t_fract *fract)
{
	float	*zoom;
	float 	interp;

	zoom = &fract->mandel->pos->zoom;
	*zoom *= (float)Z_FACTOR;
	interp = (float)(1 * Z_FACTOR);
	apply_zoom(fract->mandel, fract->mouse->Re, fract->mouse->Im, interp);
	if (fract->iter_c++ == 3)
	{
		if (fract->max_iter == K_START)
			fract->iter_c = 0;
		else
			fract->max_iter--;
		fract->iter_c = 0;
	}
}

void		shift_control(int key, t_fract *fract)
{
	if (key == 124)
		fract->mandel->pos->shift_x += (float)0.015 * (float)fract->mandel->pos->zoom;
	else if (key == 123)
		fract->mandel->pos->shift_x -= (float)0.015 * (float)fract->mandel->pos->zoom;
	else if (key == 125)
		fract->mandel->pos->shift_y -= (float)0.015 * (float)fract->mandel->pos->zoom;
	else if (key == 126)
		fract->mandel->pos->shift_y += (float)0.015 * (float)fract->mandel->pos->zoom;
}