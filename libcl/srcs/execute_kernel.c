#include "libcl.h"

void 		exec_kernel(t_cl *cl)
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

void 		*exec_kernel_color_multi(void *struc)
{
	t_cl				*cl;
	t_cl_context		*cntx;

	cl = (t_cl *)struc;
	cntx = cl->context;
	cl->dev_info->ret = clEnqueueNDRangeKernel(cntx->coms_queue,\
			cntx->color_kernel, 1, NULL, &cl->items->elems->NDRANGE,\
			&cl->items->elems->color_local_ws, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(EXEC_ERR);
		exit(1);
	}
	pthread_exit(NULL);
}

void 		exec_kernel_color(t_cl *cl)
{
	t_cl_context		*cntx;

	cntx = cl->context;
	cl->dev_info->ret = clEnqueueNDRangeKernel(cntx->coms_queue,\
			cntx->color_kernel, 1, NULL, &cl->items->elems->NDRANGE,\
			&cl->items->elems->color_local_ws, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(EXEC_ERR);
		exit(1);
	}
}

int 		*read_buff(t_cl *cl, size_t NDRANGE)
{
	int 				*res;

	res = (int *)malloc(sizeof(cl_int) * NDRANGE);
	cl->dev_info->ret = clEnqueueReadBuffer(cl->context->coms_queue,\
			cl->items->color_mem_obj,\
			CL_TRUE, 0, NDRANGE * sizeof(cl_int),\
			res, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(BUFF_READ_ERR);
		exit(1);
	}
	return (res);
}