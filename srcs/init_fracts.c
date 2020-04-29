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
	return(jul);
}

t_buddha 		*init_buddha(void)
{
	t_buddha	*bud;

	bud = (t_buddha *)malloc(sizeof(t_buddha));
	bud->c_im = 0;
	bud->c_re = 0;
	bud->re_max = 2;
	bud->re_min = -2;
	bud->im_min = -2;
	bud->im_max = bud->im_min + (bud->re_max - bud->re_min) * HEIGHT / WIDTH;
	bud->min_iter = 50;
	bud->max_iter = 10000;
	return(bud);
}