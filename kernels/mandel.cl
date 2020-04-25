#include "mandelbrot.h"

static cl_complex	position(int x, int y, local t_mandel *man, local t_pos *pos, float width, float height);
static float 		find_mu(int iter_c, cl_complex z, cl_complex c);

//-------------------------------------------------------------------
/*
 * This function finds a value of P_k
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
kernel void			vector_mandel(global int *iter,\
									global t_mandel *man,\
									constant t_pos *pos,\
									global float *mu,\
									global cl_complex *Z,\
									global cl_complex *dC)
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
	cl_complex		c = 0;
	cl_complex		z = 0; // value for iteration Z -> Z = Z * Z + C;
	cl_complex		dc = 0; // derivative with respect to c -> dC = 2.0 * dC * Z + 1.0;
	cl_complex		two = 0;
	cl_complex		one = 0;

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
	two.x = 2;
	one.x = 1;

	x = (float)tx;
	y = (float)ty;
	iter_c = 0;
	c = position(x, y, &man_l, &pos_l, width, height);

	while (cl_cmod(z) <= 100 && iter_c < (int)max_iter)
	{
		dc = cl_cmult(two, dc);
		dc = cl_cmult(dc, z);
		dc = cl_cadd(dc, one);
		z = cl_cmult(z, z);
		z = cl_cadd(z, c);
		iter_c++;
	}
	mu[index] = find_mu(iter_c, z, c);
	iter[index] = (iter_c < max_iter) ? iter_c : -1;
	dC[index] = dc;
	Z[index] = z;
}

/*
 * This function is used to find so called
 * smooth-iteration count, or log-potential scale.
 *
 * Instead of using integer-valued scale-dependant
 * on the escape radius algorithm (number of iterations
 * before the escape radius is reached), variable
 * "mu" calculates renormalized, scale-independent,
 * quasi-integral-valued iteration count.
 *
 * (more info: http://www.iquilezles.org/www/articles/mset_smooth/mset_smooth.htm)
 *
 * Variable "hi" is then used to perform smooth Hermite
 * interpolation between 0 and 1. This enables to
 * use a threshold function (mix) with a smooth transition.
 *
 * mix function returns a linear blend of x and y as:
 * 				x + (y - x) * a
 * where a is a value in the range of 0.0 to 1.0.
 *
 * Before performing those calculations, the Mandelbrot
 * equation is iterated 3 more times to reduce an error on "mu".
 */
static float 		find_mu(int iter_c, cl_complex z, cl_complex c)
{
	float mod = cl_cmod(z);
	float mu = (float)((iter_c - log2((float)log2((float)mod)) + 10));
	float hi = smoothstep(-0.1, 0.0, sin((float)(0.5 * 6.2831)));
	return ((float)mix(iter_c, mu, hi));
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
static cl_complex	position(int x, int y, local t_mandel *man, local t_pos *pos, float width, float height)
{
	float 		re_factor;
	float 		im_factor;
	cl_complex 	c;

	re_factor = (man->re_max - man->re_min) / (width - 1);
	im_factor = (man->im_max - man->im_min) / (height - 1);
	man->c_re = man->re_min + x * re_factor + pos->shift_x;
	man->c_im = man->im_max - y * im_factor + pos->shift_y;
	c.x = man->c_re;
	c.y = man->c_im;
	return(c);
}
