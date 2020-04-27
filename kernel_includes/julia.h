#ifndef _JULIA_H
# define _JULIA_H

# include "cl_complex.h.cl"

typedef struct 		s_position
{
	float  			shift_x;
	float  			shift_y;
	float 			zoom;
	float 			max_iter;
}					t_pos;

typedef struct 		s_julia
{
	float 			k_re;
	float  			k_im;
	float 			re_min;
	float 			re_max;
	float 			im_min;
	float 			im_max;
	float 			im_max_start;
	t_pos			*pos;
}					t_julia;

#endif
