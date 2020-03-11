#include "fractol.h"

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

void		map_to_zero(int row, int col, t_mandel *mandel)
{
	mandel->c_re = (col - WIDTH / 2.0) * (4.0 / WIDTH);
	mandel->c_im = (row - HEIGHT / 2.0) * (4.0 / WIDTH);
	mandel->c_re *= mandel->pos->zoom;
	mandel->c_im *= mandel->pos->zoom;
	mandel->c_re += mandel->pos->shift_x;
	mandel->c_im += mandel->pos->shift_y;
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
	mandel->x_new = x_sqr - y_sqr + mandel->c_re;
	mandel->y = 2 * xy + mandel->c_im;
	mandel->x = mandel->x_new;
}