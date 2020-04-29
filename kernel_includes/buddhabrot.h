#ifndef FRACT_OL_BUDDHABROT_H
# define FRACT_OL_BUDDHABROT_H

# include "cl_complex.h.cl"

typedef struct 		s_buddhabrot
{
	float 			c_re;
	float  			c_im;
	float 			re_min;
	float 			re_max;
	float 			im_min;
	float 			im_max;
	int 			min_iter;
	int 			max_iter;
}					t_buddha;

#endif
