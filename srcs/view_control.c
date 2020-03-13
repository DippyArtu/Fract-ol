#include "fractol.h"

void		zoom_control(int key, t_fract *fract)
{
	if (key == 24 || key == 5)
	{
		fract->mandel->pos->zoom *= 1.0 / 1.03;
		if (fract->itter_c++ == 3 && fract->max_iter != K_MAX)
		{
			fract->max_iter++;
			fract->itter_c = 0;
		}
	}
	else if (key == 27 || key == 4)
	{
		fract->mandel->pos->zoom /= 1.0 / 1.03;
		if (fract->itter_c++ == 3 && fract->max_iter > 0)
		{
			fract->max_iter--;
			fract->itter_c = 0;
		}
	}
}

void		shift_control(int key, t_fract *fract)
{
	if (key == 124)
		fract->mandel->pos->shift_x += 0.004;
	else if (key == 123)
		fract->mandel->pos->shift_x -= 0.004;
	else if (key == 125)
		fract->mandel->pos->shift_y += 0.004;
	else if (key == 126)
		fract->mandel->pos->shift_y -= 0.004;
}