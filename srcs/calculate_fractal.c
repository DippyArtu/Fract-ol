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

void		mandelbrot(t_fract *fract, t_cl *cl)
{
	t_elems		*elems;
	int 		*iter;
	int 		i;

	elems = cl->items->elems;
	if (!fract->cl_init)
	{
		i = 0;
		while (i < WIDTH)
		{
			elems->re[i] = (cl_int)i;
			i++;
		}
		i = 0;
		while (i < HEIGHT)
		{
			elems->im[i] = (cl_int)i;
			i++;
		}
		fract->cl_init = 1;
	}
	create_buffs(cl, elems, MANDEL);
	prep_kernel(cl, elems->function_name, elems->include_flag);
	exec_kernel(cl);
	iter = read_buff(cl, elems->NDRANGE);
	i = 0;
	while (i < elems->NDRANGE)
	{
		if (iter[i] > -1)
			put_pixel(fract, i, color(iter[i], fract->mandel->max_iter)); // Z is not in the set
		i++;
	}
	cl_clean_up(cl);
	free(iter);
}
