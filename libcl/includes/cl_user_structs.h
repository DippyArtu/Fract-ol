#ifndef _CL_USER_STRUCTS_H_
# define _CL_USER_STRUCTS_H_

# include "fract_structs.h"

//----------------------------------------------------------------
// This file contains structures containing objects for OpenCL to work with
// i.e. items for your actual function manipulations
//----------------------------------------------------------------

typedef struct 		s_elements
{
	int 		NDRANGE; //Total number of items (calculations to perform)
	size_t 		global_ws[2]; //Global work size
	size_t 		local_ws[2]; //Local work group
	char 		*fract_kernel_name; //Name of the vector code file (i.e. kernel.cl)
	char 		*fract_ft_name; //Name of the function to perform in the vector (i.e. vector_add)
	char 		*color_kernel_name;
	char 		*color_ft_name;
	char 		*include_flag;
	t_mandel 	*mandel;
}					t_elems;

typedef struct		s_cl_items
{
	t_elems 			*elems;
	cl_mem 				iter_mem_obj;
	cl_mem 				pos_mem_obj;
	cl_mem 				fract_mem_obj;
}					t_cl_items;

#endif