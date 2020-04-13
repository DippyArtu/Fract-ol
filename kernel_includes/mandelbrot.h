#ifndef _MANDELBROT_H_
# define _MANDELBROT_H_

typedef struct 		s_position
{
	float  			shift_x;
	float  			shift_y;
	float 			zoom;
	float 			max_iter;
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
	t_pos			*pos;
}					t_mandel;

#endif
