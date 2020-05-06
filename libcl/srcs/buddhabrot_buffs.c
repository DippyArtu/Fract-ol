#include "libcl.h"

void 		buddha_buffs(t_cl *cl, t_elems *elems)
{
	t_cl_items		*its;

	its = cl->items;
	its->fract_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_COPY_HOST_PTR,\
				sizeof(t_buddha), elems->buddha, &cl->dev_info->ret);
	its->res_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_READ_WRITE,\
				sizeof(float) * elems->buddha->n_samples, NULL, &cl->dev_info->ret);
//	its->orbits_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_WRITE_ONLY,\
//				sizeof(t_complex **) * elems->buddha->n_samples, NULL,\
//				&cl->dev_info->ret);
//	its->samples_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_COPY_HOST_PTR,\
//				sizeof(t_complex) * elems->buddha->n_samples, elems->buddha->samples,\
//				&cl->dev_info->ret);
}

void 		buddha_args(t_cl *cl)
{
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 0, sizeof(cl_mem),\
			(void *)&cl->items->fract_mem_obj);
	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 1, sizeof(cl_mem),\
			(void *)&cl->items->res_mem_obj);
//	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 1, sizeof(cl_mem),\
//			(void *)&cl->items->orbits_mem_obj);
//	cl->dev_info->ret = clSetKernelArg(cl->context->fract_kernel, 2, sizeof(cl_mem),\
//			(void *)&cl->items->samples_mem_obj);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(ARG_ERR);
		exit(1);
	}
}

