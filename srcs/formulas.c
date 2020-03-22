#include "fractol.h"

double		interpolate(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}

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
 *
 *  Real part (x) is shifted left by 0.5 so that the fractal
 *  lies central in the picture.
 *
 *  Imaginary part is stretched by a factor of 0.7 to compensate
 *  the distortion created by the screen ratio.
 *
 */

//TODO fractal distorts when trying to zoom

void		position(int x, int y, t_mandel *man)
{
	double	*s_x;
	double 	*s_y;

	s_x = &man->pos->shift_x;
	s_y = &man->pos->shift_y;
	man->c_re = (x / (WIDTH / (man->re_max - man->re_min)) + man->re_min) + *s_x;
	man->c_im =(y / (HEIGHT / (man->im_max - man->re_min)) + man->im_min) + *s_y;
	man->c_im *= 0.8;
	//printf("%f   %f\n", man->c_re, man->c_im);
}

double			sqr_mod(t_mandel *mandel)
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