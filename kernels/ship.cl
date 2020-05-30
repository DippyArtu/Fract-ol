/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.cl                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:45:42 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 15:45:42 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "burning_ship.h"

static cl_complex	position(int x, int y, local t_ship *ship, local t_pos *pos, float width, float height);
static float 		find_mu(int iter_c, cl_complex z);

//-------------------------------------------------------------------
/*
 * This function finds a value of P_k
 * to check if it lies within the Burning ship set.
 *
 * P_k+1 = (|Re(Z)| + |Im(Z)|)^2 + C -> where C is a complex number
 *
 */
kernel void			vector_ship(global int *iter,\
									global t_ship *ship,\
									constant t_pos *pos,\
									global float *mu,\
									global cl_complex *Z)
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
	float 			x_tmp;
	cl_complex		c = 0;
	cl_complex		z = 0; // value for iteration Z = (|Re(Z)| + |Im(Z)|)^2;
	cl_complex		two = 0;
	cl_complex		one = 0;

	local t_ship	ship_l;
	local t_pos		pos_l;
	ship_l = *ship;
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
	c = position(x, y, &ship_l, &pos_l, width, height);

	while (cl_cmodsqr(z) <= 100 && iter_c < (int)max_iter)
	{
		x_tmp = (cl_creal(z) * cl_creal(z) - cl_cimag(z) * cl_cimag(z)) + cl_creal(c);
		z.y = fabs(2 * cl_creal(z) * cl_cimag(z) + cl_cimag(c)) * -1;
		z.x = fabs(x_tmp);
		iter_c++;
	}
	mu[index] = find_mu(iter_c, z);
	iter[index] = (iter_c < max_iter) ? iter_c : -1;
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
 */
static float 		find_mu(int iter_c, cl_complex z)
{
	float mod = cl_cmodsqr(z);
	float mu = (float)((iter_c - log2((float)log2((float)mod)) + 10));
	float hi = smoothstep(-0.1, 0.0, sin((float)(0.5 * 6.2831)));
	return ((float)mix(iter_c, mu, hi));
}


static cl_complex	position(int x, int y, local t_ship *ship, local t_pos *pos, float width, float height)
{
	float 		re_factor;
	float 		im_factor;
	cl_complex 	c;

	re_factor = (ship->re_max - ship->re_min) / (width - 1);
	im_factor = (ship->im_max - ship->im_min) / (height - 1);
	ship->c_re = ship->re_min + x * re_factor + pos->shift_x;
	ship->c_im = ship->im_max - y * im_factor + pos->shift_y;
	c.x = ship->c_re;
	c.y = ship->c_im;
	return(c);
}
