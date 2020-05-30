/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:37:19 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 15:37:19 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcomplex.h"

/*
 *  Returns the Square root of complex number.
 *  Although a complex number has two square roots,
 *  only  one of them -the principal square root- is computed.
 *  see wikipedia:http://en.wikipedia.org/wiki/Square_root#Principal_square_root_of_a_complex_number
 */
t_complex 		cl_csqrt(const t_complex n)
{
	float 		sm;
	float 		a2;
	float 		ca2;
	float 		sa2;
	t_complex	res;

	sm = sqrt((float)(cl_cmod(n)));
	a2 = cl_carg(n) / 2;
	ca2 = cos((float)a2);
	sa2 = sin((float)a2);
	res.x = sm * ca2;
	res.y = sm * sa2;
	return(res);
}

/*
 * Computes the exponential function for the complex number z = x+iy
 * as: exp(z) = e^x(cos(y) + isin(y))
 * See: https://en.wikipedia.org/wiki/Exponential_function#Complex_plane
*/
t_complex 		cl_cexp(const t_complex n)
{
	float 		e;
	t_complex	res;

	e = exp((float)n.x);
	res.x = (e * cos((float)n.y));
	res.y = (e * sin((float)n.y));
	return(res);
}

/*
 * Computes the logatirm of the complex number z= x+iy
 * x+iy = re^{i\theta}
 * log(x+iy) = log(re^{i\theta} = log(r)+log(e^{i\theta}
 * where r is the module of |z| = sqrt(x^2+y^2)
 * log(z) = log(|z|) + iarg(z) = log(sqrt(x^2+y^2) + i atan(y/b)
 *
 * */
t_complex 		cl_clog(const t_complex z)
{
	t_complex	res;

	res.x = log((float)cl_cmod(z));
	res.y = cl_carg(z);
	return(res);
}

void			cl_bzero(t_complex *s, unsigned int n)
{
	while (n--)
	{
		s->x = 0;
		s->y = 0;
		s++;
	}
}