#include "libcl.h"
#include <stdio.h>

void 		print_log(t_cl *cl, int type)
{
	char 				*prog_log;
	size_t 				log_size;
	cl_program 			*prog;

	prog = NULL;
	if (type == 1)
		prog = &cl->context->program_fract;
	else if (type == 2)
		prog = &cl->context->program_color;
	ft_putstr(PROGRAM_BUILD_ERR);
	clGetProgramBuildInfo(*prog, cl->dev_info->device_id, \
			CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
	prog_log = (char *)malloc(sizeof(char) * (log_size + 1));
	prog_log[log_size] = '\0';
	clGetProgramBuildInfo(*prog, cl->dev_info->device_id, \
			CL_PROGRAM_BUILD_LOG, log_size + 1, prog_log, NULL);
	ft_putstr(prog_log);
	ft_putchar('\n');
	free(prog_log);
	exit(1);
}

void 		create_program(t_cl *cl)
{
	t_cl_context		*cntx;

	cntx = cl->context;
	cntx->program_fract = clCreateProgramWithSource(cntx->context, 1,\
			(const char **)&cl->kernel_src->fract_src_str,\
			(const size_t *)&cl->kernel_src->fract_src_size,\
			&cl->dev_info->ret);
	cntx->program_color = clCreateProgramWithSource(cntx->context, 1,\
			(const char **)&cl->kernel_src->color_src_str,\
			(const size_t *)&cl->kernel_src->color_src_size,\
			&cl->dev_info->ret);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(PROGRAM_ERR);
		exit(1);
	}
}

void 		build_program(t_cl *cl, char *include)
{
	t_cl_context		*cntx;
	cl_int 				err;

	cntx = cl->context;
	err = cl->dev_info->ret = clBuildProgram(cntx->program_fract, 1,\
			&cl->dev_info->device_id, include, NULL, NULL);
	if (cl->dev_info->ret < 0)
		print_log(cl, 1);
	err = cl->dev_info->ret = clBuildProgram(cntx->program_color, 1,\
			&cl->dev_info->device_id, include, NULL, NULL);
	if (cl->dev_info->ret < 0)
		print_log(cl, 2);
}

void 		prep_kernel(t_cl *cl, char *kernel_ft, char *include)
{
	t_cl_context		*cntx;

	cntx = cl->context;
	create_program(cl);
	build_program(cl, include);
	cntx->fract_kernel = clCreateKernel(cntx->program_fract,\
			kernel_ft, &cl->dev_info->ret);
	cntx->color_kernel = clCreateKernel(cntx->program_color,\
			COLOR_KERNEL_FT, &cl->dev_info->ret);
	if (cl->dev_info->ret < 0)
	{
		printf("%i\n", cl->dev_info->ret);
		ft_putstr(KERNEL_CREAT_ERR);
		exit(1);
	}
}

//TODO too big

void 		set_kernel_args(t_cl *cl)
{
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 0, sizeof(cl_mem),\
			(void *)&cl->items->iter_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 1, sizeof(cl_mem),\
			(void *)&cl->items->fract_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 2, sizeof(cl_mem),\
			(void *)&cl->items->pos_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 3, sizeof(cl_mem),\
			(void *)&cl->items->mu_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 4, sizeof(cl_mem),\
			(void *)&cl->items->z_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 5, sizeof(cl_mem),\
			(void *)&cl->items->dc_mem_obj);

	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel, 0, sizeof(cl_mem),\
			(void *)&cl->items->iter_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel, 1, sizeof(cl_mem),\
			(void *)&cl->items->color_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel, 2, sizeof(cl_mem),\
			(void *)&cl->items->color_struct_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel, 3, sizeof(cl_mem),\
			(void *)&cl->items->mu_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel, 4, sizeof(cl_mem),\
			(void *)&cl->items->z_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel, 5, sizeof(cl_mem),\
			(void *)&cl->items->dc_mem_obj);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(ARG_ERR);
		exit(1);
	}
}