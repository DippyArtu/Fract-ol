/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.cl                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:45:36 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 15:45:36 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

static cl_complex	position(int x, int y, local t_julia *jul, local t_pos *pos, float width, float height);
static float 		find_mu(int iter_c, cl_complex z);

kernel void			vector_julia(global int *iter,\
									global t_julia *jul,\
									constant t_pos *pos,\
									global float *mu,\
									global cl_complex *Z,\
									global cl_complex *dK)
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
	cl_complex		k = 0;
	cl_complex		z = 0; // value for iteration Z -> Z = Z * Z + k;
	cl_complex		dk = 0; // derivative with respect to k -> dK = 2.0 * dK * Z + 1.0;
	cl_complex		two = 0;
	cl_complex		one = 0;

	local t_julia	jul_l;
	local t_pos		pos_l;
	jul_l = *jul;
	pos_l = *pos;

	k.x = jul_l.k_re;
	k.y = jul_l.k_im;

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
	z = position(x, y, &jul_l, &pos_l, width, height);

	while (cl_cmodsqr(z) <= 100 && iter_c < (int)max_iter)
	{
		dk = cl_cmult(two, dk);
		dk = cl_cmult(dk, z);
		dk = cl_cadd(dk, one);
		z = cl_cmult(z, z);
		z = cl_cadd(z, k);
		iter_c++;
	}
	mu[index] = find_mu(iter_c, z);
	iter[index] = (iter_c < max_iter) ? iter_c : -1;
	dK[index] = dk;
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

//-------------------------------------------------------------------
/*
 *  Julia set, like Mandelbrot, lies within a circle of radius R.
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
static cl_complex	position(int x, int y, local t_julia *jul, local t_pos *pos, float width, float height)
{
	cl_complex	k;
	int 		l = (width < height) ? width : height;
	float 		scale_fact = 1.5;

	k.x = 2 * scale_fact * (x - width / 2) / l + pos->shift_x;
	k.y = 2 * scale_fact * (y - height / 2) / l + pos->shift_y;
	return(k);
}
