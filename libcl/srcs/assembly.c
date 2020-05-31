/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:46:31 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 18:08:33 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void		print_log(t_cl *cl, int type)
{
	char				*prog_log;
	size_t				log_size;
	cl_program			*prog;

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

void		create_program(t_cl *cl)
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

void		build_program(t_cl *cl, char *include)
{
	t_cl_context		*cntx;

	cntx = cl->context;
	cl->dev_info->ret = clBuildProgram(cntx->program_fract, 1,\
			&cl->dev_info->device_id, include, NULL, NULL);
	if (cl->dev_info->ret < 0)
		print_log(cl, 1);
	cl->dev_info->ret = clBuildProgram(cntx->program_color, 1,\
			&cl->dev_info->device_id, include, NULL, NULL);
	if (cl->dev_info->ret < 0)
		print_log(cl, 2);
}

void		prep_kernel(t_cl *cl, char *kernel_ft, char *include)
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
		ft_putstr(KERNEL_CREAT_ERR);
		exit(1);
	}
}

void		set_kernel_args(t_cl *cl, int type)
{
	if (type == MANDEL)
		mandel_args(cl);
	else if (type == JULIA)
		julia_args(cl);
	else if (type == SHIP)
		ship_args(cl);
}
