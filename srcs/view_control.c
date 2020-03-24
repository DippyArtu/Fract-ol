#include "fractol.h"

double		interpolate(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}

void		apply_zoom(t_mandel *man, double m_re, double m_im, double interp)
{
	man->re_max = interpolate(m_re, man->re_max, interp);
	if (man->re_max > 2.0)
		man->re_max = 2.0;
	man->re_min = interpolate(m_re, man->re_min, interp);
	if (man->re_min < -2.0)
		man->re_min = -2.0;
	man->im_max = interpolate(m_im, man->im_max, interp);
	if (man->im_max > man->im_max_start)
		man->im_max = man->im_max_start;
	man->im_min = interpolate(m_im, man->im_min, interp);
	if (man->im_min < -2.0)
		man->im_min = -2.0;
}

//TODO num of itteration doesn't increase if zoom in after zoom out

void		zoom_control(int key, t_fract *fract)
{
	double	*zoom;
	double 	interp;

	zoom = &fract->mandel->pos->zoom;
	if (key == 5)
	{
		*zoom /= Z_FACTOR;
		interp = 1.0 / Z_FACTOR;
		apply_zoom(fract->mandel, fract->mouse->Re, fract->mouse->Im, interp);
		if (fract->itter_c++ == 3 && fract->max_iter != K_MAX)
		{
			fract->max_iter++;
			fract->itter_c = 0;
		}
	}
	else if (key == 4)
	{
		*zoom *= Z_FACTOR;
		interp = 1.0 * Z_FACTOR;
		apply_zoom(fract->mandel, fract->mouse->Re, fract->mouse->Im, interp);
		if (fract->itter_c++ == 3 && fract->max_iter > K_START)
		{
			fract->max_iter--;
			fract->itter_c = 0;
		}
	}
}

void		shift_control(int key, t_fract *fract)
{
	if (key == 124)
		fract->mandel->pos->shift_x += 0.015 * fract->mandel->pos->zoom;
	else if (key == 123)
		fract->mandel->pos->shift_x -= 0.015 * fract->mandel->pos->zoom;
	else if (key == 125)
		fract->mandel->pos->shift_y -= 0.015 * fract->mandel->pos->zoom;
	else if (key == 126)
		fract->mandel->pos->shift_y += 0.015 * fract->mandel->pos->zoom;
}