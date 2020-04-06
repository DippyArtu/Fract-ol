#include "fractol.h"

int					mouse_press(int key, int x, int y, void *p)
{
	t_fract			*fract;

	(void)x;
	(void)y;
	fract = (t_fract *)p;
	if (key == 5)
		zoom_in(fract);
	else if (key == 4)
		zoom_out(fract);
	fill_background(fract);
	draw(fract, fract->cl, fract->type);
	if (key == 1)
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

int 					mouse_move(int x, int y, void *p)
{
	t_fract			*fract;
	t_mandel		*man;
	double 			re_factor;
	double 			im_factor;

	fract = (t_fract *)p;
	man = fract->mandel;
	re_factor = (man->re_max - man->re_min) / (WIDTH - 1);
	im_factor = (man->im_max - man->im_min) / (HEIGHT - 1);
	fract->mouse->Re = man->re_min + x * re_factor;
	fract->mouse->Im = man->im_max - y * im_factor;
	return (0);
}