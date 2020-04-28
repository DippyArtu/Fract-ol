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
	t_pos			*pos;
}					t_julia;

#endif
