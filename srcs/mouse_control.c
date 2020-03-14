#include "fractol.h"

int					mouse_press(int key, int x, int y, void *p)
{
	t_fract			*fract;

	(void)x;
	(void)y;
	fract = (t_fract *)p;
	if (key == 4 || key == 5)
	{
		zoom_control(key, fract);
		fill_background(fract);
		draw(fract, fract->type);
	}
	else if (key == 1)
		fract->mouse->press = 1;
	return (0);
}

int					mouse_release(int key, int x, int y, void *p)
{
	t_fract			*fract;

	(void)x;
	(void)y;
	(void)key;
	fract = (t_fract *)p;
	fract->mouse->press = 0;
	return (0);
}

int 					mouse_move(int re, int im, void *p)
{
	t_fract			*fract;

	fract = (t_fract *)p;
	fract->mouse->Re = (re - WIDTH / 2.0) * 4.0 / WIDTH;
	fract->mouse->Im = (im - HEIGHT / 2.0) * 4.0 / WIDTH;
	if (fract->mouse->press)
	{
		fill_background(fract);
		draw(fract, fract->type);
		fract->mandel->pos->zoom *= 1.0 / 1.03;
		if (fract->itter_c++ == 3 && fract->max_iter != K_MAX)
		{
			fract->max_iter++;
			fract->itter_c = 0;
		}
	}
	return (0);
}