#include "libcl.h"

void 		exec_kernel(t_cl *cl)
{
	//-------------------------------------------------------------------
	//Execute the OpenCL kernel on the list
	//-------------------------------------------------------------------
	t_cl_context		*cntx;

	cntx = cl->context;
	cl->dev_info->ret = clEnqueueNDRangeKernel(cntx->command_queue,\
			cntx->kernel, 2, NULL, cl->items->elems->global_ws,\
			cl->items->elems->local_ws,
			0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(EXEC_ERR);
		exit(1);
	}
}

int 		*read_buff(t_cl *cl, int NDRANGE)
{
	int 				*res;

	res = (int *)malloc(sizeof(cl_int) * NDRANGE); //Change type to the desired type
	cl->dev_info->ret = clEnqueueReadBuffer(cl->context->command_queue,\
			cl->items->iter_mem_obj, //Change this to the actual object which will host the result of a calculation
			CL_TRUE, 0, NDRANGE * sizeof(cl_int), //Change type to the desired type
			res, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(BUFF_READ_ERR);
		exit(1);
	}
	return (res);
}