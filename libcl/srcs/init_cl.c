#include "libcl.h"

t_cl		*init_opencl_structs(void)
{
	t_cl			*cl;

	if (!(cl = (t_cl *)malloc(sizeof(t_cl))))
		malloc_fail();
	if (!(cl->context = (t_cl_context *)malloc(sizeof(t_cl_context))))
		malloc_fail();
	if (!(cl->dev_info = (t_cl_dev_info *)malloc(sizeof(t_cl_dev_info))))
		malloc_fail();
	if (!(cl->kernel_src = (t_cl_kernel_src *)malloc(sizeof(t_cl_kernel_src))))
		malloc_fail();
	if (!(cl->kernel_src->fract_src_str = (char *)malloc(MAX_SOURCE_SIZE)))
		malloc_fail();
	if (!(cl->kernel_src->color_src_str = (char *)malloc(MAX_SOURCE_SIZE)))
		malloc_fail();
	init_user_cl_structs(cl);
	return (cl);
}

void 		init_user_cl_structs(t_cl *cl)
{
	if (!(cl->items = (t_cl_items *)malloc(sizeof(t_cl_items))))
		malloc_fail();
	cl->items->elems = NULL;
}

t_elems		*init_opencl_elems(char *k_name, char *ft_name, char *inc)
{
	t_elems			*elems;

	if (!(elems = (t_elems *)malloc(sizeof(t_elems))))
		malloc_fail();
	elems->NDRANGE = WIDTH * HEIGHT;
	elems->global_ws[0] = WIDTH;
	elems->global_ws[1] = HEIGHT;
	elems->local_ws[0] = 10;
	elems->local_ws[1] = 10;
	elems->color_local_ws = 100;
	elems->fract_kernel_name = k_name;
	elems->fract_ft_name = ft_name;
	elems->include_flag = inc;
	elems->mandel = NULL;
	elems->julia = NULL;
	elems->buddha = NULL;
	elems->color = NULL;
	return (elems);
}