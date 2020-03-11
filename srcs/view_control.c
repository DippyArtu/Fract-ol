#include "fractol.h"

void		zoom_control(int key, t_fract *fract)
{
	if (key == 27)
	{
		fract->mandel->pos->zoom /= 1.0 / 1.05;
		if (fract->mandel->max_iter > 20)
			fract->mandel->max_iter++;
	}
	else if (key == 24)
	{
		fract->mandel->pos->zoom *= 1.0 / 1.05;
		if (fract->mandel->max_iter <= K_MAX)
			fract->mandel->max_iter++;
	}
}

void		shift_control(int key, t_fract *fract)
{
	if (key == 126)
		fract->mandel->pos->shift_y -= 0.005;
	else if (key == 125)
		fract->mandel->pos->shift_y += 0.005;
	else if (key == 123)
		fract->mandel->pos->shift_x -= 0.005;
	else if (key == 124)
		fract->mandel->pos->shift_x += 0.005;
}