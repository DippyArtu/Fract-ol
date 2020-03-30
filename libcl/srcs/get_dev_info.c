#include "libcl.h"

void 		get_cl_info(t_cl *cl)
{
	t_cl_dev_info		*inf;

	inf = cl->dev_info;
	inf->platform_id = NULL;
	inf->device_id = NULL;
	inf->ret = clGetPlatformIDs(1, &inf->platform_id, &inf->num_platforms);

	//---------------------------------------------------------------------------------
	//Change CL_DEVICE_TYPE_DEFAULT to ..._GPU or ..._CPU depending on a desired device
	// i.e, for GPU use CL_DEVICE_TYPE_GPU
	//---------------------------------------------------------------------------------

	inf->ret = clGetDeviceIDs(inf->platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &inf->device_id, &inf->num_devices);
}