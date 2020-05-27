#include "libcl.h"

void 		load_kernel_src_code(char *kernel, t_cl *cl)
{
	cl->kernel_src->fd_fract = open(kernel, O_RDONLY);
	cl->kernel_src->fd_color = open(COLOR_KERNEL_FILE, O_RDONLY);
	if (cl->kernel_src->fd_fract <= 0 || cl->kernel_src->fd_color <= 0)
	{
		ft_putstr(KERNEL_LOAD_ERR);
		exit(1);
	}
	cl->kernel_src->fract_src_size = read(cl->kernel_src->fd_fract,\
			cl->kernel_src->fract_src_str,\
			MAX_SOURCE_SIZE);
	cl->kernel_src->color_src_size = read(cl->kernel_src->fd_color,\
			cl->kernel_src->color_src_str,\
			MAX_SOURCE_SIZE);
	close(cl->kernel_src->fd_fract);
	close(cl->kernel_src->fd_color);
}

void 		create_context_coms_queue(t_cl *cl)
{
	t_cl_context		*cntx;

	cntx = cl->context;
	cntx->context = clCreateContext(NULL, 1, &cl->dev_info->device_id,\
			NULL, NULL, &cl->dev_info->ret);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(CONTEXT_ERR);
		exit(1);
	}
	cntx->coms_queue = clCreateCommandQueue(cntx->context,\
			cl->dev_info->device_id, 0, &cl->dev_info->ret);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(QUEUE_ERR);
		exit(1);
	}
}

void 		create_buffs(t_cl *cl, t_elems *elems, int type)
{
	t_cl_items			*its;

	its = cl->items;
	its->color_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_READ_WRITE,\
						(WIDTH * HEIGHT) * sizeof(cl_int), NULL, &cl->dev_info->ret);
	if (type == MANDEL)
		mandel_buffs(cl, elems);
	else if (type == JULIA)
		julia_buffs(cl, elems);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(BUFF_CREAT_ERR);
		exit(1);
	}
	set_kernel_args(cl, type);
}
