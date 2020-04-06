#ifndef _FRACT_STRUCTS_H
# define _FRACT_STRUCTS_H

typedef struct	s_mouse
{
	int			press;
	double		x;
	double		y;
	double 		Re;
	double 		Im;
}				t_mouse;

typedef struct 		s_position
{
	double  		shift_x;
	double  		shift_y;
	double 			zoom;
}					t_pos;

typedef struct 		s_mandelbrot
{
	double 			c_re;
	double  		c_im;
	double 			x;
	double 			y;
	double 			x_sqr;
	double 			y_sqr;
	double 			re_min;
	double 			re_max;
	double 			im_min;
	double 			im_max;
	double 			im_max_start;
	int 			max_iter;
	t_pos			*pos;
}					t_mandel;

#endif
