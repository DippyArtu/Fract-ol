#include "fractol.h"

int					mouse_press(int key, int x, int y, void *p)
{
	t_fract			*fract;

	(void)x;
	(void)y;
	fract = (t_fract *)p;
	if (key == 4 || key == 5)
		zoom_control(key, fract);
	fill_background(fract);
	draw(fract, fract->type);
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

//TODO y axis isn't being taken into account

int 					mouse_move(int x, int y, void *p)
{
	t_fract			*fract;
	t_mandel		*man;

	fract = (t_fract *)p;
	man = fract->mandel;
	fract->mouse->Re = x / (WIDTH / (man->re_max - man->re_min)) + man->re_min;
	fract->mouse->Im = x / (WIDTH / (man->re_max - man->re_min)) + man->re_min;
	y = x;

	//printf("%f     %f    |     %i     %i\n", fract->mouse->Re, fract->mouse->Im, x, y);
	return (0);
}