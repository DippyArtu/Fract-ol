#include "fractol.h"

t_mandel		*init_mandelbrot(void)
{
	t_mandel	*man;

	if (!(man = (t_mandel *)malloc(sizeof(t_mandel))))
		error(3);
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

	if (!(jul = (t_julia *)malloc(sizeof(t_julia))))
		error(3);
	jul->k_re = (float)-0.4;
	jul->k_im = (float)0.6;
	return(jul);
}

//TODO look here
t_buddha 		*init_buddha(void)
{
	t_buddha	*bud;

	if (!(bud = (t_buddha *)malloc(sizeof(t_buddha))))
		error(3);
	bud->c_im = 0;
	bud->c_re = 0;
	bud->re_max = 2;
	bud->re_min = -2;
	bud->im_min = -2;
	bud->im_max = 2;
	bud->n_samples = B_HEIGHT * B_WIDTH;
	bud->max_heatmap_val = 0;
	bud->width = B_WIDTH;
	bud->height = B_HEIGHT;
	bud->max_iter = 50;
	return(bud);
}