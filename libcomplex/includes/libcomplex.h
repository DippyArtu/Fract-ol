/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcomplex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:37:05 by Artur             #+#    #+#             */
/*   Updated: 2020/06/02 16:39:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOMPLEX_H
# define LIBCOMPLEX_H

# include <opencl-c-base.h>
# include <math.h>

typedef float2			t_complex;

# define I_CL ((cl_complex)(0.0, 1.0))
# define PI_CL 3.14159265358979323846
# define E_CL 2.718281828459045235360

float			cl_creal(t_complex n);
float			cl_cimag(t_complex n);
float			cl_cmod(t_complex n);
float			cl_cmodsqr(t_complex n);
t_complex		cl_cadd(t_complex a, t_complex b);
t_complex		cl_cmult(t_complex a, t_complex b);
t_complex		cl_cpow(t_complex base, int exp);
t_complex		cl_cdiv(t_complex a, t_complex b);
float			cl_carg(t_complex a);
t_complex		cl_csqrt(t_complex n);
t_complex		cl_cexp(t_complex n);
t_complex		cl_clog(t_complex z);
float			cl_cdot(t_complex a, t_complex b);
void			cl_bzero(t_complex *s, unsigned int n);

#endif
