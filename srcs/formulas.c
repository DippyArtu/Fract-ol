#include "fractol.h"

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

void		position(int x, int y, t_mandel *man)
{
	double	*s_x;
	double 	*s_y;
	double 	re_factor;
	double 	im_factor;

	s_x = &man->pos->shift_x;
	s_y = &man->pos->shift_y;
	re_factor = (man->re_max - man->re_min) / (WIDTH - 1);
	im_factor = (man->im_max - man->im_min) / (HEIGHT - 1);
	man->c_re = man->re_min + x * re_factor + *s_x;
	man->c_im = man->im_max - y * im_factor + *s_y;
}

double			sqr_mod(t_mandel *mandel)
{
	mandel->x_sqr = mandel->x * mandel->x;
	mandel->y_sqr = mandel->y * mandel->y;
	return(mandel->x_sqr + mandel->y_sqr);
}

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

void		find_p(t_mandel *mandel)
{
	double	xy_d;

	xy_d = mandel->x + mandel->y;
	xy_d *= xy_d;
	mandel->x = mandel->x_sqr - mandel->y_sqr + mandel->c_re;
	mandel->y = xy_d - mandel->x_sqr - mandel->y_sqr + mandel->c_im;
}