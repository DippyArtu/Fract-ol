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
	t_pos			*pos;
}					t_mandel;

typedef struct		s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image;
	char			*data_addr;
	int				bpp;
	int				size_line;
	int				endian;
	int 			type;
	int 			iter_c;
	int 			max_iter;
	t_mandel		*mandel;
	t_mouse			*mouse;
}					t_fract;

#endif
