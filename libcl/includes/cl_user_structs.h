#ifndef _CL_USER_STRUCTS_H_
# define _CL_USER_STRUCTS_H_

//----------------------------------------------------------------
// This file contains structures containing objects for OpenCL to work with
// i.e. items for your actual function manipulations
//----------------------------------------------------------------

typedef struct 		s_elements
{
	int 		*a;  //Variable a
	int 		*b;  //Variable b
	int 		NDRANGE; //Total number of items (calculations to perform)
	char 		*kernel_name; //Name of the vector code file (i.e. kernel.cl)
	char 		*function_name; //Name of the function to perform in the vector (i.e. vector_add)
}					t_elems;

typedef struct		s_cl_items
{
	cl_mem 				a_mem_obj;
	cl_mem 				b_mem_obj;
	cl_mem 				c_mem_obj;
}					t_cl_items;

#endif
