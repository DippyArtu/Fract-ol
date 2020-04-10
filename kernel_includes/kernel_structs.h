#ifndef _STRUCTS_H_
# define _STRUCTS_H_

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
	int 			max_iter;
	t_pos			*pos;
}					t_mandel;

void		position(int x, int y, global t_mandel *man);
float		sqr_mod(global t_mandel *mandel);
void		find_p(global t_mandel *mandel);

#endif
