#include "fractol.h"

t_mandel		*init_mandelbrot(void)
{
	t_mandel	*man;

	man = (t_mandel *)malloc(sizeof(t_mandel));
	man->c_im = 0;
	man->c_re = 0;
	man->re_max = 2;
	man->re_min = -2;
	man->im_min = -2;
	man->im_max = man->im_min + (man->re_max - man->re_min) * HEIGHT / WIDTH;
	man->im_max_start = man->im_max;
	return(man);
}

t_julia 		*init_julia(void)
{
	t_julia		*jul;

	jul = (t_julia *)malloc(sizeof(t_julia));
	jul->k_re = (float)-0.4;
	jul->k_im = (float)0.6;
	jul->re_max = 2;
	jul->re_min = -2;
	jul->im_min = -2;
	jul->im_max = jul->im_min + (jul->re_max - jul->re_min) * HEIGHT / WIDTH;
	jul->im_max_start = jul->im_max;
	return(jul);
}