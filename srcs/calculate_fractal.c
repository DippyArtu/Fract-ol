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
 *
 * 	This calculation is performed using OpenCL in the
 * 	mandel.cl kernel.
 *
 * 	The color calculation is also performed on OpenCL
 * 	in the color.cl kernel.
 */

static void 	delay(int t)
{
	int 	i;

	i = 0;
	while (i < t)
	{
		i++;
	}
}

void			mandelbrot(t_fract *fract, t_cl *cl)
{
	t_elems		*elems;
	int 		*color;
	int 		i;
	pthread_t 	thread;

	i = 0;
	elems = cl->items->elems;
	create_buffs(cl, elems, MANDEL);
	exec_kernel(cl, FRACTOL);
	delay(1);
	if (pthread_create(&thread, NULL, exec_kernel_color, (void *)cl))
	{
		ft_putstr(THREAD_ERR);
		exit(-1);
	}
	color = read_buff(cl, elems->NDRANGE);
	while (i < (int)elems->NDRANGE)
	{
		if (color[i] == -1)
			put_pixel(fract, i, BLACK); // Z is in the set
		else
			put_pixel(fract, i, color[i]); // Z is not in the set
		i++;
	}
	cl_clean_mem_objs(cl);
	free(color);
}
