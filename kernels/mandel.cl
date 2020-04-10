#include "mandelbrot.h"

kernel void		vector_mandel(global const int *re,\
								global const int *im,\
								global int *iter,\
								global t_mandel *man,\
								constant t_pos *pos)
{
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
	position(x, y, man, pos);
	while (sqr_mod(man) <= 4 && iter_c < man->max_iter)
	{
		find_p(man);
		iter_c++;
	}
	if (iter_c < man->max_iter)
		iter[ty * (int)pos->width + tx] = iter_c;
	else
		iter[ty * (int)pos->width + tx] = -1;
}

void			position(int x, int y, global t_mandel *man, constant t_pos *pos)
{
	float	s_x;
	float 	s_y;
	float 	re_factor;
	float 	im_factor;

	s_x = pos->shift_x;
	s_y = pos->shift_y;
	re_factor = (man->re_max - man->re_min) / (pos->width - 1);
	im_factor = (man->im_max - man->im_min) / (pos->height - 1);
	man->c_re = man->re_min + x * re_factor + s_x;
	man->c_im = man->im_max - y * im_factor + s_y;
}

float			sqr_mod(global t_mandel *mandel)
{
	mandel->x_sqr = mandel->x * mandel->x;
	mandel->y_sqr = mandel->y * mandel->y;
	return(mandel->x_sqr + mandel->y_sqr);
}

void			find_p(__global t_mandel *mandel)
{
	float	xy_d;

	xy_d = mandel->x + mandel->y;
	xy_d *= xy_d;
	mandel->x = mandel->x_sqr - mandel->y_sqr + mandel->c_re;
	mandel->y = xy_d - mandel->x_sqr - mandel->y_sqr + mandel->c_im;
}