#ifndef _FRACT_STRUCTS_H
# define _FRACT_STRUCTS_H

typedef unsigned int 	t_heatmap;
typedef int 			t_atomic_int;

typedef struct 			s_color
{
	float 				max_iter;
	int 				mode;
	float 				angle;
}						t_color;

typedef struct			s_mouse
{
	int					press;
	float				x;
	float				y;
	float 				Re;
	float 				Im;
}						t_mouse;

typedef struct 			s_position
{
	float  				shift_x;
	float  				shift_y;
	float 				zoom;
	float 				max_iter;
}						t_pos;

typedef struct 			s_mandelbrot
{
	float 				c_re;
	float  				c_im;
	float 				re_min;
	float 				re_max;
	float 				im_min;
	float 				im_max;
	float 				im_max_start;
	t_pos				*pos;
	t_color				*color;
}						t_mandel;

typedef struct 			s_julia
{
	float 				k_re;
	float  				k_im;
	t_pos				*pos;
	t_color				*color;
}						t_julia;

typedef struct 			s_buddhabrot
{
	float2 				**orbits;
	t_heatmap 			**res;
	t_heatmap 			max_heatmap_val;
	float2				*samples;
	int 				thread_c;
	int					width;
	int 				height;
	float 				c_re;
	float  				c_im;
	float 				re_min;
	float 				re_max;
	float 				im_min;
	float 				im_max;
	int 				max_iter;
	int					n_samples;
}						t_buddha;

#endif
