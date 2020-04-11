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
	cntx->command_queue = clCreateCommandQueue(cntx->context,\
			cl->dev_info->device_id, 0, &cl->dev_info->ret);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(QUEUE_ERR);
		exit(1);
	}
}

void 		create_buffs(t_cl *cl, t_elems *elems, int type)
{
	//---------------------------------------------------------------------------------
	//Here, buffers for each given vector of the program should be declared and processed
	//Below is a template for the test code
	//Items are stored in the t_cl_items structure
	//---------------------------------------------------------------------------------
	t_cl_items			*its;

	its = cl->items;
	//---------------------------------------------------------------------------------
	//Declare "CL_MEM_READ_ONLY" for the read array (i.e. things to sum together),
	// or "CL_MEM_WRITE_ONLY" for the write array (i.e. result)
	// or "CL_MEM_USE_HOST_PTR" to use host memory area as buff (i.e. if you passing a structure)
	//
	//Change "sizeof(int)" to the appropriate type
	//---------------------------------------------------------------------------------

	// Configure this to create an object which will store your result
	its->iter_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_READ_WRITE,\
			(WIDTH * HEIGHT) * sizeof(cl_int), NULL, &cl->dev_info->ret);
	its->color_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_WRITE_ONLY,\
			(WIDTH * HEIGHT) * sizeof(cl_int), NULL, &cl->dev_info->ret);
	its->max_iter_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_READ_ONLY,\
			sizeof(cl_float), NULL, &cl->dev_info->ret);
	cl->dev_info->ret = clEnqueueWriteBuffer(cl->context->command_queue,\
			cl->items->max_iter_mem_obj, CL_TRUE, 0, sizeof(cl_float),\
			&elems->mandel->max_iter, 0, NULL, NULL);
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(BUFF_CPY_ERR);
		exit(1);
	}
	if (type == 1)
	{
		its->fract_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_COPY_HOST_PTR,\
				sizeof(t_mandel), elems->mandel, &cl->dev_info->ret);
		its->pos_mem_obj = clCreateBuffer(cl->context->context, CL_MEM_COPY_HOST_PTR,\
				sizeof(t_pos), elems->mandel->pos, &cl->dev_info->ret);
	}
	if (cl->dev_info->ret < 0)
	{
		ft_putstr(BUFF_CREAT_ERR);
		exit(1);
	}
	set_kernel_args(cl);
}