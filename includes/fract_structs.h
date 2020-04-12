#ifndef _FRACT_STRUCTS_H
# define _FRACT_STRUCTS_H

typedef struct 		s_color
{
	float 			max_iter;
	int 			mode;
}					t_color;

typedef struct		s_mouse
{
	int				press;
	float			x;
	float			y;
	float 			Re;
	float 			Im;
}					t_mouse;

typedef struct 		s_position
{
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
	float 			max_iter;
	t_pos			*pos;
	t_color			*color;
}					t_mandel;

#endif
