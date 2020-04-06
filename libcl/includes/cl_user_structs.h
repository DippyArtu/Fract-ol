#ifndef _CL_USER_STRUCTS_H_
# define _CL_USER_STRUCTS_H_

# include "fract_structs.h"

//----------------------------------------------------------------
// This file contains structures containing objects for OpenCL to work with
// i.e. items for your actual function manipulations

typedef struct 		s_elements
{
	int 		*re;  //Variable for x pixel coordinates
	int 		*im;  //Variable for y pixel coordinates
	int 		NDRANGE; //Total number of items (calculations to perform)
	char 		*kernel_name; //Name of the vector code file (i.e. kernel.cl)
	char 		*function_name; //Name of the function to perform in the vector (i.e. vector_add)
	char 		*include_flag;
	t_mandel 	*mandel;
}					t_elems;

typedef struct		s_cl_items
{
	t_elems 			*elems;
	cl_mem 				re_mem_obj;
	cl_mem 				im_mem_obj;
	cl_mem 				iter_mem_obj;
	cl_mem 				fract_mem_obj;
}					t_cl_items;

#endif