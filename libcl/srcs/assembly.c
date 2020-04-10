#include "libcl.h"

void 		print_log(t_cl *cl)
{
	char 				*prog_log;
	size_t 				log_size;

	ft_putstr(PROGRAM_BUILD_ERR);
	clGetProgramBuildInfo(cl->context->program, cl->dev_info->device_id, \
			CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
	prog_log = (char *)malloc(sizeof(char) * (log_size + 1));
	prog_log[log_size] = '\0';
	clGetProgramBuildInfo(cl->context->program, cl->dev_info->device_id, \
			CL_PROGRAM_BUILD_LOG, log_size + 1, prog_log, NULL);
	ft_putstr(prog_log);
	ft_putchar('\n');
	free(prog_log);
	exit(1);
}

void 		prep_kernel(t_cl *cl, char *kernel_name, char *include)
{
	t_cl_context		*cntx;
	cl_int 				err;

	cntx = cl->context;
	//Create a program from the kernel source
	cntx->program = clCreateProgramWithSource(cntx->context, 1,\
			(const char **)&cl->kernel_src->source_str,\
			(const size_t *)&cl->kernel_src->source_size,\
			&cl->dev_info->ret);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(PROGRAM_ERR);
		exit(1);
	}

	//Build the program
	err = cl->dev_info->ret = clBuildProgram(cntx->program, 1,\
			&cl->dev_info->device_id, include, NULL, NULL);
	if (cl->dev_info->ret < 0)
		print_log(cl);

	//Create the OpenCL kernel
	cntx->kernel = clCreateKernel(cntx->program, kernel_name, &cl->dev_info->ret);
	set_kernel_args(cl);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(KERNEL_CREAT_ERR);
		exit(1);
	}
}

void 		set_kernel_args(t_cl *cl)
{
	//Set arguments of the kernel according to the template below
	//Change "cl->items->a_mem_obj" to the actual memory object
	cl->dev_info->ret = clSetKernelArg(cl->context->kernel, 0, sizeof(cl_mem),\
			(void *)&cl->items->re_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->kernel, 1, sizeof(cl_mem),\
			(void *)&cl->items->im_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->kernel, 2, sizeof(cl_mem),\
			(void *)&cl->items->iter_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->kernel, 3, sizeof(cl_mem),\
			(void *)&cl->items->fract_mem_obj);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(ARG_ERR);
		exit(1);
	}
}