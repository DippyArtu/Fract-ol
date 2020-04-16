#include "mandelbrot.h"

static void			position(int x, int y, local t_mandel *man, local t_pos *pos, float width, float height);
static float		sqr_mod(local t_mandel *mandel);
static void			find_p(local t_mandel *mandel);

/*
 *  This function tests whether a point
 *  lies within the mandelbrot set or not.
 */
kernel void			vector_mandel(global int *iter, global t_mandel *man, constant t_pos *pos, global float *mu)
{
	int 			tx;
	int 			ty;
	int 			index;
	float 			x;
	float 			y;
	int 			iter_c;
	float 			max_iter;
	float 			width;
	float 			height;
	float 			mod;

	local t_mandel	man_l;
	local t_pos		pos_l;
	man_l = *man;
	pos_l = *pos;


	tx = get_global_id(0);
	ty = get_global_id(1);
	width = get_global_size(0);
	height = get_global_size(1);
	index = ty * (int)width + tx;
	max_iter = pos_l.max_iter;

	x = (float)tx;
	y = (float)ty;
	iter_c = 0;
	man_l.x = 0;
	man_l.y = 0;
	position(x, y, &man_l, &pos_l, width, height);
	while ((mod = sqr_mod(&man_l)) <= (float)4 && iter_c < max_iter)
	{
		find_p(&man_l);
		iter_c++;
	}
	mu[index] = iter_c - (log((float)log((float)mod)) / log((float)2));
	iter[index] = (iter_c < max_iter) ? iter_c : -1;
}

//-------------------------------------------------------------------
/*
 *  Mandelbrot set lies within a circle of radius 2.
 *
 *  The visible area then lies within a rectangle defined
 *  by RE_MIN, RE_MAX, IM_MIN, IM_MAX, where RE is a
 *  real part of a complex number (x coordinate) and IM
 *  is an imaginary part (y coordinate).
 *
 *  To map this area to the center of the screen, the
 *  "position" function is used, which outputs given
 *  coordinates relative to (0,0).
 */
static void			position(int x, int y, local t_mandel *man, local t_pos *pos, float width, float height)
{
	float 	re_factor;
	float 	im_factor;

	re_factor = (man->re_max - man->re_min) / (width - 1);
	im_factor = (man->im_max - man->im_min) / (height - 1);
	man->c_re = man->re_min + x * re_factor + pos->shift_x;
	man->c_im = man->im_max - y * im_factor + pos->shift_y;
}

//-------------------------------------------------------------------
/*
 *  Before returning sum of squares,
 *  this function will write the
 *  x squared and y squared values into
 *  the structure, so that the time-costly
 *  operation of squaring is performed only
 *  once per iteration.
 */
static float		sqr_mod(local t_mandel *mandel)
{
	mandel->x_sqr = mandel->x * mandel->x;
	mandel->y_sqr = mandel->y * mandel->y;
	return(mandel->x_sqr + mandel->y_sqr);
}

//-------------------------------------------------------------------
/*
 * This formula finds a value of P_k
 * to check if it lies within the Mandlebrot set.
 *
 * P_k+1 = Z(^2) + C -> where C is a complex number
 *
 *           __                             __
 *          | X_k+1 = X(^2)_k - Y(^2)_k + X_0 |
 * P_k+1 =  |                                 |
 *          | Y_k+1 = 2(X_k * Y_k) + Y_0      |
 *           --                             --
 *
 *           where X & Y are all real numbers
 */

static void			find_p(local t_mandel *mandel)
{
	float	xy_d;

	xy_d = mandel->x + mandel->y;
	xy_d *= xy_d;
	mandel->x = mandel->x_sqr - mandel->y_sqr + mandel->c_re;
	mandel->y = xy_d - mandel->x_sqr - mandel->y_sqr + mandel->c_im;
}