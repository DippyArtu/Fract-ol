#include "fractol.h"

double		interpolate(double start, double end, double inter)
{
	return start + ((end - start) * inter);
}

/*
 *  Mandelbrot set lies within a circle of radius 2,
 *  therefore, the width of the image should be 4
 *
 *  To map the center of the image to (0,0),
 *  given a pixel, we subtract half of the image height
 *  from the vertical coordinate (imaginary component) and
 *  half of the width from horizontal coordinate (real component).
 *
 *  Then, scale the result so that the image lies within the
 *  length of the Mandelbrot set (4)
 */

void		position(int x, int y, t_mandel *man)
{
	man->c_re = (x / (WIDTH / (man->re_max - man->re_min)) + man->re_min) - 0.5;
	man->c_im = (y / (HEIGHT / (man->im_max - man->re_min)) + man->im_min) * 0.7;
}

int			sqr_mod(t_mandel *mandel)
{
	return(mandel->x * mandel->x + mandel->y * mandel->y);
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
	double 	x_sqr;
	double 	y_sqr;
	double	xy;

	x_sqr = mandel->x * mandel->x;
	y_sqr = mandel->y * mandel->y;
	xy = mandel->x * mandel->y;
	mandel->x = x_sqr - y_sqr + mandel->c_re;
	mandel->y = 2 * xy + mandel->c_im;
}