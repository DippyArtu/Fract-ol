#include "fractol.h"

/*
 *  The Mandelbrod fractal is a graphical
 *  representation of all the numbers that
 *  lie in the Mandelbrot set.
 *
 *  This set consists of a sequence of numbers
 *  P_k, which, when iterated through the formula
 *
 *  P_k+1 = P_k(^2) + c, where c is a complex number,
 *
 *   K_MAX times, the module of P_k is less then or equal to
 *   the divergence radius (2) -> |P_k|<=R
 *
 *   This means that, when iterated (per assumption,
 *   an infinite amount of times), the point P_k will either
 *   always stay within the divergence radius of 2, oscillating
 *   with a period of 4, or converge to a single point.
 *
 *   If, on the other hand, |P_k| > R, the point lies outside the
 *   Mandelbrot set, as it will diverge to infinity, displaying
 *   chaotic behaviour.
 */

void		mandelbrot(t_mandel *mandel, t_fract *fract)
{
	int 		row;  // y coordinate
	int 		col;  // x coordinate
	int 		iter;

	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			mandel->x = 0;
			mandel->y = 0;
			map_to_zero(row, col, mandel);
			iter = 0;
			while ((sum_of_sqrs(mandel) <= (4 / mandel->pos->zoom)) && iter < mandel->max_iter)
			{
				find_p(mandel);
				iter++;
			}
			if (iter < mandel->max_iter)
				put_pixel(fract, col, row, color(iter)); // P_k is not in the set
			else
				put_pixel(fract, col, row, BLACK); // P_k is in the set
			col++;
		}
		row++;
	}
}