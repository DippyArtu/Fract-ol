/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:37:25 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 18:36:02 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcomplex.h"

t_complex		cl_cadd(const t_complex a, const t_complex b)
{
	t_complex	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_complex		cl_cmult(const t_complex a, const t_complex b)
{
	t_complex	res;

	res.x = (a.x * b.x - a.y * b.y);
	res.y = (a.x * b.y + a.y * b.x);
	return (res);
}

/*
** Computes the integer power of a complex number.
*/

t_complex		cl_cpow(const t_complex base, int exp)
{
	t_complex	res;

	res.x = 1;
	res.y = 1;
	while (exp)
	{
		if (exp & 1)
			res = cl_cmult(res, base);
		exp >>= 1;
		res = cl_cmult(res, res);
	}
	return (res);
}

t_complex		cl_cdiv(const t_complex a, const t_complex b)
{
	float		dividend;
	t_complex	res;

	dividend = (b.x * b.x + b.y * b.y);
	res.x = ((a.x * b.x + a.y * b.y) / dividend);
	res.y = ((a.y * b.x - a.x * b.y) / dividend);
	return (res);
}

/*
** Get the argument of a complex number (its angle):
** http://en.wikipedia.org/wiki/Complex_number#Absolute_value_and_argument
*/

float			cl_carg(const t_complex a)
{
	if (a.x > 0)
		return (atan((float)(a.y / a.x)));
	else if (a.x < 0 && a.y >= 0)
		return (atan((float)(a.y / a.x)) + Pi_cl);
	else if (a.x < 0 && a.y < 0)
		return (atan((float)(a.y / a.x)) - Pi_cl);
	else if (a.x == 0 && a.y > 0)
		return ((float)(Pi_cl / 2));
	else if (a.x == 0 && a.y < 0)
		return ((float)(Pi_cl * -1) / 2);
	else
		return (0);
}
