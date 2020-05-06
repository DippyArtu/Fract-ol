#ifndef _CL_USER_STRUCTS_H_
# define _CL_USER_STRUCTS_H_

# include "fract_structs.h"

typedef struct 		s_elements
{
	size_t 			NDRANGE;
	size_t 			global_ws[2];
	size_t 			local_ws[2];
	size_t 			color_local_ws;
	char 			*fract_kernel_name;
	char 			*fract_ft_name;
	char 			*include_flag;
	t_mandel 		*mandel;
	t_julia			*julia;
	t_buddha		*buddha;
	t_color			*color;
}					t_elems;

typedef struct		s_cl_items
{
	t_elems 		*elems;
	cl_mem 			iter_mem_obj;
	cl_mem 			mu_mem_obj;
	cl_mem 			color_struct_mem_obj;
	cl_mem 			color_mem_obj;
	cl_mem 			pos_mem_obj;
	cl_mem 			fract_mem_obj;
	cl_mem 			z_mem_obj;
	cl_mem			dc_mem_obj;
	cl_mem 			heatmap_mem_obj;
	cl_mem 			samples_mem_obj;
	cl_mem 			res_mem_obj;
	cl_mem 			orbits_mem_obj;
}					t_cl_items;

#endif
