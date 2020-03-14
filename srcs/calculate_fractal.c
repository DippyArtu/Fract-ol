//TODO mouse is always relative to 0,0

#include "fractol.h"

/*
 *  The Mandelbrod fractal is a graphical
 *  representation of all the numbers that
 *  lie in the Mandelbrot set.
 *
 *  This set consists of a sequence of complex numbers
 *  Z, which, when iterated through the formula
 *
 *  		   Z_k+1 = Z_k(^2) + c,
 *
 *  where c is a complex number, K_MAX times,
 *  the module of P_k is less then or equal to
 *  the divergence radius R = 2.
 *
 *  				|Z|<=R
 *
 *  This means that, when iterated (with assumption,
 *  an infinite amount of times), the point P_k will either
 *  always stay within the divergence radius of 2 oscillating
 *  or converge to a single point.
 *
 *  If, on the other hand, |Z_k| > R, the point lies outside the
 *  Mandelbrot set, as it will diverge to infinity, displaying
 *  chaotic behaviour.
 *
 *  This can be calculated using natural numbers:
 *
 *  				P = x + yi
 *  			   |P| = (x(^2) + y(^2))(^ -1/2)
 *  			   P(^2) = x(^2) + y(^2)
 *
 * 	Working with a squared modulus saves an extra step, which
 * 	is a time consuming one (taking a square root).
 *
 * 	R, therefore, becomes R(^2) = 4.
 */

void		mandelbrot(t_mandel *mandel, t_fract *fract)
{
	int 			y;  // y pixel coordinate
	int 			x;  // x pixel coordinate
	int				iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandel->x = 0;
			mandel->y = 0;
			position(x, y, mandel, fract);
			iter = 0;
			while (sqr_mod(mandel) <= 4 && iter < fract->max_iter)
			{
				find_p(mandel);
				iter++;
			}
			if (iter < fract->max_iter)
				put_pixel(fract, x, y, color(iter)); // Z is not in the set
			x++;
		}
		y++;
	}
}