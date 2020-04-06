#include "kernel_structs.h"

//TODO figure out calculations

void		position(int x, int y, __global t_mandel *man)
{
	double	*s_x;
	double 	*s_y;
	double 	re_factor;
	double 	im_factor;

	s_x = &man->pos->shift_x;
	s_y = &man->pos->shift_y;
	re_factor = (man->re_max - man->re_min) / (800 - 1); //WIDTH
	im_factor = (man->im_max - man->im_min) / (600 - 1); //HEIGHT
	man->c_re = man->re_min + x * re_factor + *s_x;
	man->c_im = man->im_max - y * im_factor + *s_y;
}

double			sqr_mod(__global t_mandel *mandel)
{
	mandel->x_sqr = mandel->x * mandel->x;
	mandel->y_sqr = mandel->y * mandel->y;
	return(mandel->x_sqr + mandel->y_sqr);
}

void		find_p(__global t_mandel *mandel)
{
	double	xy_d;

	xy_d = mandel->x + mandel->y;
	xy_d *= xy_d;
	mandel->x = mandel->x_sqr - mandel->y_sqr + mandel->c_re;
	mandel->y = xy_d - mandel->x_sqr - mandel->y_sqr + mandel->c_im;
}

__kernel void		mandel_calc(__global const int *re, __global const int *im, __global int *iter, __global t_mandel *man)
{
	unsigned int 	i;
	int 			x;
	int 			y;
	int 			iter_c;

	i = get_global_id(0);
	x = re[i];
	y = im[i];
	iter_c = 0;
	man->x = 0;
	man->y = 0;
	position(x, y, man);
	while (sqr_mod(man) <= 4 && iter_c < man->max_iter)
	{
		find_p(man);
		iter_c++;
	}
	if (iter_c < man->max_iter)
		iter[i] = iter_c;
	else
		iter[i] = -1;
}


//			mandel->x = 0;
//			mandel->y = 0;
//			position(re, im, mandel);
//			iter = 0;
//			while (sqr_mod(mandel) <= 4 && iter < fract->max_iter)
//			{
//				find_p(mandel);
//				iter++;
//			}
//			if (iter < fract->max_iter)
//				put_pixel(fract, i, color(iter, fract->max_iter)); // Z is not in the set