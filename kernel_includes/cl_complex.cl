#ifndef CL_COMPLEX_H_CL
#define CL_COMPLEX_H_CL

typedef float2 cl_complex;
# define I_cl ((cl_complex)(0.0, 1.0))
# define Pi_cl 3.14159265358979323846
# define E_cl 2.718281828459045235360

float			cl_creal(cl_complex n);
float			cl_cimag(cl_complex n);
float			cl_cmod(cl_complex n);
cl_complex		cl_cadd(cl_complex a, cl_complex b);
cl_complex 		cl_cmult(cl_complex a, cl_complex b);
cl_complex 		cl_cpow(cl_complex base , int exp);
cl_complex 		cl_cdiv(cl_complex a, cl_complex b);
float 			cl_carg(cl_complex a);
cl_complex 		cl_csqrt(cl_complex n);
cl_complex 		cl_cexp(cl_complex n);
cl_complex 		cl_clog(cl_complex z);
float			cl_cdot(cl_complex a, cl_complex b);


float			cl_creal(const cl_complex n)
{
	return(n.x);
}

float			cl_cimag(const cl_complex n)
{
	return(n.y);
}

/*
 * Returns modulus of complex number (its length):
 */
float			cl_cmod(const cl_complex n)
{
	return(sqrt((float)((n.x * n.x) + (n.y * n.y))));
}

/*
 The dot product of two vectors a = [a1, a2, ..., an] and b = [b1, b2, ..., bn] is defined as:
 d = a1b1 + a2b2
*/
float			cl_cdot(const cl_complex a, const cl_complex b)
{
	return((a.x * b.x) + (a.y * b.y));
}

cl_complex		cl_cadd(const cl_complex a, const cl_complex b)
{
	cl_complex		res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return(res);
}

cl_complex 		cl_cmult(const cl_complex a, const cl_complex b)
{
	cl_complex		res;

	res.x = (a.x * b.x - a.y * b.y);
	res.y = (a.x * b.y + a.y * b.x);
	return (res);
}

/*
 * Computes the integer power of a complex number.
*/
cl_complex 		cl_cpow(const cl_complex base , int exp)
{
	cl_complex	res;

	res.x = 1;
	res.y = 1;
	while(exp)
	{
		if(exp & 1)
			res=cl_cmult(res, base);
		exp>>= 1;
		res = cl_cmult(res, res);
	}
	return (res);
}

cl_complex 		cl_cdiv(const cl_complex a, const cl_complex b)
{
	float		dividend;
	cl_complex	res;

	dividend = (b.x * b.x + b.y * b.y);
	res.x = ((a.x * b.x + a.y * b.y) / dividend);
	res.y = ((a.y * b.x - a.x * b.y) / dividend);
	return(res);
}

/*
 * Get the argument of a complex number (its angle):
 * http://en.wikipedia.org/wiki/Complex_number#Absolute_value_and_argument
 */
float 			cl_carg(const cl_complex a)
{
	if(a.x > 0)
		return(atan((float)(a.y / a.x)));
	else if(a.x < 0 && a.y >= 0)
		return(atan((float)(a.y / a.x)) + Pi_cl);
	else if(a.x < 0 && a.y < 0)
		return(atan((float)(a.y / a.x)) - Pi_cl);
	else if(a.x == 0 && a.y > 0)
		return((float)(Pi_cl / 2));
	else if(a.x == 0 && a.y < 0)
		return((float)(Pi_cl * -1) / 2);
	else
		return(0);
}

/*
 *  Returns the Square root of complex number.
 *  Although a complex number has two square roots,
 *  only  one of them -the principal square root- is computed.
 *  see wikipedia:http://en.wikipedia.org/wiki/Square_root#Principal_square_root_of_a_complex_number
 */
cl_complex 		cl_csqrt(const cl_complex n)
{
	const float sm = sqrt((float)(cl_cmod(n)));
	const float a2 = cl_carg(n) / 2;
	const float ca2 = cos((float)a2);
	const float sa2 = sin((float)a2);
	cl_complex	res;

	res.x = sm * ca2;
	res.y = sm * sa2;
	return(res);
}

/*
 * Computes the exponential function for the complex number z = x+iy
 * as: exp(z) = e^x(cos(y) + isin(y))
 * See: https://en.wikipedia.org/wiki/Exponential_function#Complex_plane
*/
cl_complex 		cl_cexp(const cl_complex n)
{
	const float e = exp((float)n.x);
	cl_complex	res;

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
cl_complex 		cl_clog(const cl_complex z)
{
	cl_complex	res;

	res.x = log((float)cl_cmod(z));
	res.y = cl_carg(z);
	return(res);
}

#endif
