#include "fractol.h"

void				restart(t_fract *fract)
{
	mlx_destroy_image(fract->mlx_ptr, fract->image);
	fract->image = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	fract->data_addr = mlx_get_data_addr(fract->image, &(fract->bpp),
										&(fract->size_line), &(fract->endian));
	fill_background(fract);
	draw(fract, fract->type);
}

double interpolate(double start, double end, double interpolation)
{
	return start + ((end - start) * interpolation);
}

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

//int					mouse_move(int x, int y, void *p)
//{
//	t_fract			*fract;
//
//	fract = (t_fract *)p;
//	fract->mouse->x = x;
//	fract->mouse->y = y;
//	return (0);
//}

int 					mouse_move(int re, int im, void *p)
{
	t_fract			*fract;
	double 			interpolation;

	fract = (t_fract *)p;
	interpolation = 1.0 / 1.01;
	if (fract->mouse->press)
	{
		fract->mandel->c_re = interpolate(re, fract->mandel->c_re, interpolation);
		fract->mandel->c_im = interpolate(im, fract->mandel->c_im, interpolation);
		//printf("%f     %f\n", fract->mandel->c_re, fract->mandel->c_im);
		restart(fract);
	}
	return (0);
}