#include "libcl.h"

void 		cl_clean_mem_objs(t_cl *cl)
{
	t_cl_items			*its;
	t_cl_dev_info		*di;

	its = cl->items;
	di = cl->dev_info;
	di->ret = clReleaseMemObject(its->fract_mem_obj);
	di->ret = clReleaseMemObject(its->color_mem_obj);
	di->ret = clReleaseMemObject(its->iter_mem_obj);
	di->ret = clReleaseMemObject(its->color_struct_mem_obj);
	di->ret = clReleaseMemObject(its->pos_mem_obj);
	di->ret = clReleaseMemObject(its->mu_mem_obj);
	di->ret = clReleaseMemObject(its->z_mem_obj);
	di->ret = clReleaseMemObject(its->dc_mem_obj);
}

void 		cl_clean_structs(t_cl *cl, t_elems *elems)
{
	free(cl->kernel_src->fract_src_str);
	free(cl->kernel_src->color_src_str);
	free(cl->kernel_src);
	free(cl->dev_info);
	free(cl->context);
	free(cl->items);
	free(elems);
	free(cl);
}

void 		cl_clean_up_all(t_cl *cl)
{
	t_cl_dev_info		*di;

	di = cl->dev_info;
	di->ret = clReleaseKernel(cl->context->fract_kernel);
	di->ret = clReleaseKernel(cl->context->color_kernel);
	di->ret = clReleaseProgram(cl->context->program_fract);
	di->ret = clReleaseProgram(cl->context->program_color);
	di->ret = clFlush(cl->context->coms_queue);
	di->ret = clFinish(cl->context->coms_queue);
	di->ret = clReleaseCommandQueue(cl->context->coms_queue);
	di->ret = clReleaseContext(cl->context->context);
}
