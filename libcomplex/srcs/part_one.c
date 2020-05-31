/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:37:12 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 18:33:55 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcomplex.h"

float			cl_creal(const t_complex n)
{
	return (n.x);
}

float			cl_cimag(const t_complex n)
{
	return (n.y);
}

/*
** Returns modulus of complex number (its length)
*/

float			cl_cmod(const t_complex n)
{
	return (sqrt((float)((n.x * n.x) + (n.y * n.y))));
}

float			cl_cmodsqr(const t_complex n)
{
	return ((float)((n.x * n.x) + (n.y * n.y)));
}

/*
** The dot product of two vectors a = [a1, a2, ..., an]
** and b = [b1, b2, ..., bn] is defined as:
** d = a1b1 + a2b2
*/

float			cl_cdot(const t_complex a, const t_complex b)
{
	return ((a.x * b.x) + (a.y * b.y));
}
