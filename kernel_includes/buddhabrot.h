#ifndef FRACT_OL_BUDDHABROT_H
# define FRACT_OL_BUDDHABROT_H

# include "cl_complex.h.cl"

typedef unsigned int 	t_heatmap;

typedef struct 			s_buddhabrot
{
	float2	 			**orbits;
	t_heatmap			**res;
	t_heatmap 			max_heatmap_val;
	float2	 			*samples;
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
