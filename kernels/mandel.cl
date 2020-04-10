#include "kernel_structs.h"

//TODO sort this out

void		position(int x, int y, global t_mandel *man)
{
	float	*s_x;
	float 	*s_y;
	float 	re_factor;
	float 	im_factor;

	s_x = &man->pos->shift_x;
	s_y = &man->pos->shift_y;
//	printf("%f\n", man->pos->shift_x);
	re_factor = (man->re_max - man->re_min) / (800 - 1); //WIDTH
	im_factor = (man->im_max - man->im_min) / (600 - 1); //HEIGHT
	man->c_re = man->re_min + x * re_factor + *s_x;
	man->c_im = man->im_max - y * im_factor + *s_y;
}

float			sqr_mod(global t_mandel *mandel)
{
	mandel->x_sqr = mandel->x * mandel->x;
	mandel->y_sqr = mandel->y * mandel->y;
	return(mandel->x_sqr + mandel->y_sqr);
}

void		find_p(__global t_mandel *mandel)
{
	float	xy_d;

	xy_d = mandel->x + mandel->y;
	xy_d *= xy_d;
	mandel->x = mandel->x_sqr - mandel->y_sqr + mandel->c_re;
	mandel->y = xy_d - mandel->x_sqr - mandel->y_sqr + mandel->c_im;
}

kernel void		vector_mandel(global const int *re, global const int *im, global int *iter, global t_mandel *man)
{
	int 			width = 800;
	int 			height = 600;
	int 			tx;
	int 			ty;
	int 			x;
	int 			y;
	int 			iter_c;

	tx = get_global_id(0);
	ty = get_global_id(1);

	x = re[tx];
	y = im[ty];
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
		iter[ty * width + tx] = iter_c;
	else
		iter[ty * width + tx] = -1;
}