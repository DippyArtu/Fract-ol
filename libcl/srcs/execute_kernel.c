#include "libcl.h"

//TODO watch work group size (originally 64)
#include <stdio.h>

void 		exec_kernel(t_cl *cl, int NDRANGE)
{
	//-------------------------------------------------------------------
	//Execute the OpenCL kernel on the list
	//-------------------------------------------------------------------
	t_cl_context		*cntx;

	size_t 				gws[2];
	gws[0] = 800;
	gws[1] = 600;

	size_t 				lgs[2];
	lgs[0] = 2;
	lgs[1] = 2;

	cntx = cl->context;
	cntx->ndrange = NDRANGE;
	cntx->work_group = 1; //You can change this to a desired size of a work group
	cl->dev_info->ret = clEnqueueNDRangeKernel(cntx->command_queue,\
			cntx->kernel, 2, NULL, gws, lgs,\
			0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		printf("%i\n", cl->dev_info->ret);
		ft_putstr(EXEC_ERR);
		exit(1);
	}
}

int 		*read_buff(t_cl *cl, int NDRANGE)
{
	int 				*res;

	res = (int *)malloc(sizeof(int) * NDRANGE); //Change type to the desired type
	cl->dev_info->ret = clEnqueueReadBuffer(cl->context->command_queue,\
			cl->items->iter_mem_obj, //Change this to the actual object which will host the result of a calculation
			CL_TRUE, 0, NDRANGE * sizeof(int), //Change type to the desired type
			res, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(BUFF_READ_ERR);
		exit(1);
	}
	return (res);
}