/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_kernel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:46:47 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 18:12:54 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void		exec_kernel(t_cl *cl)
{
	t_cl_context		*cntx;

	cntx = cl->context;
	cl->dev_info->ret = clEnqueueNDRangeKernel(cntx->coms_queue,\
			cntx->fract_kernel, 2, NULL, cl->items->elems->global_ws,\
			cl->items->elems->local_ws, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(EXEC_ERR);
		exit(1);
	}
}

void		exec_kernel_color(t_cl *cl)
{
	t_cl_context		*cntx;

	cntx = cl->context;
	cl->dev_info->ret = clEnqueueNDRangeKernel(cntx->coms_queue,\
			cntx->color_kernel, 1, NULL, &cl->items->elems->ndrange,\
			&cl->items->elems->color_local_ws, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(EXEC_ERR);
		exit(1);
	}
}

int			*read_buff(t_cl *cl, size_t ndrange)
{
	int					*res;

	res = (int *)malloc(sizeof(cl_int) * ndrange);
	cl->dev_info->ret = clEnqueueReadBuffer(cl->context->coms_queue,\
			cl->items->color_mem_obj,\
			CL_TRUE, 0, ndrange * sizeof(cl_int),\
			res, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(BUFF_READ_ERR);
		exit(1);
	}
	return (res);
}
