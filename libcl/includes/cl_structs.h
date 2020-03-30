#ifndef _CL_STRUCTS_H_
# define _CL_STRUCTS_H_

# include <OpenCL/opencl.h>
# include <opencl-c-base.h>
# include "cl_user_structs.h"

typedef struct 		s_cl_kernel_src
{
	int 				fd;
	char				*source_str;
	size_t				source_size;
}					t_cl_kernel_src;

typedef struct 		s_cl_dev_info
{
	cl_platform_id		platform_id;
	cl_device_id 		device_id;
	cl_uint 			num_devices;
	cl_uint 			num_platforms;
	cl_int 				ret;
}					t_cl_dev_info;

typedef  struct		s_cl_context
{
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;
	size_t 				ndrange;
	size_t 				work_group;
}					t_cl_context;

typedef struct		s_cl
{
	t_cl_context		*context;
	t_cl_dev_info		*dev_info;
	t_cl_kernel_src		*kernel_src;
	//Include links to the working structures below
	t_cl_items			*items;
}					t_cl;

#endif
