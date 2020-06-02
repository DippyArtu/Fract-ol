/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_buffs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 23:51:38 by Artur             #+#    #+#             */
/*   Updated: 2020/06/02 16:39:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void		ship_buffs(t_cl *cl, t_elems *elems)
{
	t_cl_items			*its;

	its = cl->items;
	its->fract_mem_obj = clCreateBuffer(cl->context->context,\
			CL_MEM_COPY_HOST_PTR,\
				sizeof(t_ship), elems->ship, &cl->dev_info->ret);
	its->pos_mem_obj = clCreateBuffer(cl->context->context,\
			CL_MEM_COPY_HOST_PTR,\
				sizeof(t_pos), elems->ship->pos, &cl->dev_info->ret);
	its->z_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_READ_WRITE,\
				(WIDTH * HEIGHT) * sizeof(cl_float2), NULL, &cl->dev_info->ret);
	its->dc_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_READ_WRITE,\
				sizeof(cl_float2), NULL, &cl->dev_info->ret);
	its->iter_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_READ_WRITE,\
			(WIDTH * HEIGHT) * sizeof(cl_int), NULL, &cl->dev_info->ret);
	its->mu_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_READ_WRITE,\
			(WIDTH * HEIGHT) * sizeof(cl_float), NULL, &cl->dev_info->ret);
	its->color_struct_mem_obj = clCreateBuffer(cl->context->context,\
				CL_MEM_COPY_HOST_PTR, sizeof(t_color),\
				elems->color, &cl->dev_info->ret);
}

void		ship_args(t_cl *cl)
{
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel,\
			0, sizeof(cl_mem),\
			(void *)&cl->items->iter_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel,\
			1, sizeof(cl_mem),\
			(void *)&cl->items->fract_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel,\
			2, sizeof(cl_mem),\
			(void *)&cl->items->pos_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel,\
			3, sizeof(cl_mem),\
			(void *)&cl->items->mu_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel,\
			4, sizeof(cl_mem),\
			(void *)&cl->items->z_mem_obj);
	ship_color_args(cl);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(ARG_ERR);
		exit(1);
	}
}

void		ship_color_args(t_cl *cl)
{
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel,\
			0, sizeof(cl_mem),\
			(void *)&cl->items->iter_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel,\
			1, sizeof(cl_mem),\
			(void *)&cl->items->color_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel,\
			2, sizeof(cl_mem),\
			(void *)&cl->items->color_struct_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel,\
			3, sizeof(cl_mem),\
			(void *)&cl->items->mu_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel,\
			4, sizeof(cl_mem),\
			(void *)&cl->items->z_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->color_kernel,\
			5, sizeof(cl_mem),\
			(void *)&cl->items->dc_mem_obj);
}
