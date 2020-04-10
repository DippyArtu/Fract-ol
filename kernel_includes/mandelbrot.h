#ifndef _MANDELBROT_H_
# define _MANDELBROT_H_

typedef struct 		s_position
{
	float 			width;
	float 			height;
	float  			shift_x;
	float  			shift_y;
	float 			zoom;
}					t_pos;

typedef struct 		s_mandelbrot
{
	float 			c_re;
	float  			c_im;
	float 			x;
	float 			y;
	float 			x_sqr;
	float 			y_sqr;
	float 			re_min;
	float 			re_max;
	float 			im_min;
	float 			im_max;
	float 			im_max_start;
	int 			max_iter;
	t_pos			*pos;
}					t_mandel;

//-------------------------------------------------------------------
/*
 *  Mandelbrot set lies within a circle of radius 2.
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
void				position(int x, int y, global t_mandel *man, constant t_pos *pos);
//-------------------------------------------------------------------

//-------------------------------------------------------------------
/*
 *  Before returning sum of squares,
 *  this function will write the
 *  x squared and y squared values into
 *  the structure, so that the time-costly
 *  operation of squaring is performed only
 *  once per iteration.
 */
float				sqr_mod(global t_mandel *mandel);
//-------------------------------------------------------------------

//-------------------------------------------------------------------
/*
 * This formula finds a value of P_k
 * to check if it lies within the Mandlebrot set.
 *
 * P_k+1 = Z(^2) + C -> where C is a complex number
 *
 *           __                             __
 *          | X_k+1 = X(^2)_k - Y(^2)_k + X_0 |
 * P_k+1 =  |                                 |
 *          | Y_k+1 = 2(X_k * Y_k) + Y_0      |
 *           --                             --
 *
 *           where X & Y are all real numbers
 */
void				find_p(global t_mandel *mandel);
//-------------------------------------------------------------------

#endif
