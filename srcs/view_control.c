#include "fractol.h"

void		zoom_control(int key, t_fract *fract)
{
	double		interp;

	if (key == 5)
	{
		interp = 1.0 / fract->mandel->pos->z_factor;
		apply_zoom(fract->mandel, fract->mouse->Re, fract->mouse->Im, interp);
		if (fract->itter_c++ == 3 && fract->max_iter != K_MAX)
		{
			fract->max_iter++;
			fract->itter_c = 0;
		}
	}
	else if (key == 4)
	{
		interp = 1.0 * fract->mandel->pos->z_factor;
		apply_zoom(fract->mandel, fract->mouse->Re, fract->mouse->Im, interp);
		if (fract->itter_c++ == 3 && fract->max_iter > 0)
		{
			fract->max_iter--;
			fract->itter_c = 0;
		}
	}
}

void		apply_zoom(t_mandel *man, double m_re, double m_im, double interp)
{
	man->re_min = interpolate(m_re, man->re_min, interp);
	man->im_min = interpolate(m_im, man->im_min, interp);
	man->re_max = interpolate(m_re, man->re_max, interp);
	man->im_max = interpolate(m_im, man->im_max, interp);
}

//TODO move has to be proportional to the zoom factor

void		shift_control(int key, t_fract *fract)
{
	if (key == 124)
		fract->mandel->pos->shift_x += (1.0 / 1.03) / fract->mandel->pos->z_factor;
	else if (key == 123)
		fract->mandel->pos->shift_x -= (1.0 / 1.03) / fract->mandel->pos->z_factor;
	else if (key == 125)
		fract->mandel->pos->shift_y += (1.0 / 1.03) / fract->mandel->pos->z_factor;
	else if (key == 126)
		fract->mandel->pos->shift_y -= (1.0 / 1.03) / fract->mandel->pos->z_factor;
}