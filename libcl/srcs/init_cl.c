#include "libcl.h"
#include "fract_defines.h"

//-------------------------------------------------------------------
// Init OpenCL structures
//-------------------------------------------------------------------
t_cl		*init_opencl_structs(void)
{
	t_cl			*cl;

	cl = (t_cl *)malloc(sizeof(t_cl));
	cl->context = (t_cl_context *)malloc(sizeof(t_cl_context));
	cl->dev_info = (t_cl_dev_info *)malloc(sizeof(t_cl_dev_info));
	cl->kernel_src = (t_cl_kernel_src *)malloc(sizeof(t_cl_kernel_src));
	cl->kernel_src->source_str = (char *)malloc(MAX_SOURCE_SIZE);
	init_user_cl_structs(cl); //Init your structures here
	return (cl);
}

//-------------------------------------------------------------------
// Init OpenCL structures for your data
//
// Change this functions to suit you
//-------------------------------------------------------------------
void 		init_user_cl_structs(t_cl *cl)
{
	cl->items = (t_cl_items *)malloc(sizeof(t_cl_items));
	cl->items->elems = NULL;
}

//TODO find good local_ws

t_elems		*init_opencl_elems(char *k_name, char *ft_name, char *inc)
{
	t_elems			*elems;

	elems = (t_elems *)malloc(sizeof(t_elems));
	elems->NDRANGE = WIDTH * HEIGHT; //Total number of elements in the array to be processed
	elems->global_ws[0] = WIDTH;
	elems->global_ws[1] = HEIGHT;
	elems->local_ws[0] = 25;
	elems->local_ws[1] = 10;
	elems->kernel_name = k_name;
	elems->function_name = ft_name;
	elems->include_flag = inc;
	elems->mandel = NULL;
	return (elems);
}