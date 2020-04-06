#ifndef _STRUCTS_H_
# define _STRUCTS_H_

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

void		position(int x, int y, __global t_mandel *man);
double		sqr_mod(__global t_mandel *mandel);
void		find_p(__global t_mandel *mandel);

#endif
