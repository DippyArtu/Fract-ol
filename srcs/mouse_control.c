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

int 					mouse_move(int x, int y, void *p)
{
	t_fract			*fract;

	fract = (t_fract *)p;
	fract->mouse->Re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
	if (x > WIDTH)
		fract->mouse->Re = ReMax;
	else if (x < 0)
		fract->mouse->Re = ReMin;
	fract->mouse->Im = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
	if (y > HEIGHT)
		fract->mouse->Im = ImMax;
	else if (y < 0)
		fract->mouse->Im = ImMin;

	printf("%f     %f    |     %i     %i\n", fract->mouse->Re, fract->mouse->Im, x, y);
	return (0);
}