#include "libcl.h"

void 		prep_kernel(t_cl *cl, char *kernel_name)
{
	t_cl_context		*cntx;

	cntx = cl->context;

	//Create a program from the kernel source
	cntx->program = clCreateProgramWithSource(cntx->context, 1,\
			(const char **)&cl->kernel_src->source_str,\
			(const size_t *)&cl->kernel_src->source_size,\
			&cl->dev_info->ret);

	//Build the program
	cl->dev_info->ret = clBuildProgram(cntx->program, 1,\
			&cl->dev_info->device_id, NULL, NULL, NULL);

	//Create the OpenCL kernel
	cntx->kernel = clCreateKernel(cntx->program, kernel_name, &cl->dev_info->ret);
	set_kernel_args(cl);
}

void 		set_kernel_args(t_cl *cl)
{
	//Set arguments of the kernel according to the template below
	//Change "cl->items->a_mem_obk" to the actual memory object
	cl->dev_info->ret = clSetKernelArg(cl->context->kernel, 0, sizeof(cl_mem),\
			(void *)&cl->items->a_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->kernel, 1, sizeof(cl_mem),\
			(void *)&cl->items->b_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->kernel, 2, sizeof(cl_mem),\
			(void *)&cl->items->c_mem_obj);
}