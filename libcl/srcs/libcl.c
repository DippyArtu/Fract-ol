#include "libcl.h"

int 		*opencl_calc(t_cl *cl, t_elems *elems)
{
	int 		*res;
	//Load the kernel source code into the array source_str
	load_kernel_src_code(elems->kernel_name, cl);

	//Get platform and device information
	//---------------------------------------------------------------------------------
	//Change CL_DEVICE_TYPE_DEFAULT in "get_dev_info" function
	// to ..._GPU or ..._CPU depending on a desired device
	// i.e, for GPU use CL_DEVICE_TYPE_GPU
	//---------------------------------------------------------------------------------
	get_cl_info(cl);

	//-------------------------------------------------------------------
	//Create an OpenCl context & command queue
	create_context_coms_queue(cl);

	//-------------------------------------------------------------------
	//Create memory buffers on the device for each vector &
	//Copy the lists A and B to their respective memory buffers
	//
	//Instead of "a", "b", pass actual pointers to the input arrays
	//Also, go into the function and change it according to your needs
	create_buffs(cl, elems->a, elems->b, elems->NDRANGE);

	//-------------------------------------------------------------------
	//This will create a program from the kernel source,
	//build the program, create an OpenCL kernel and set arguments to it
	//
	//Give the name of an actual kernel function as a second argument here
	//
	//Go into the function and change "set_kernel_args" function to suit your needs
	prep_kernel(cl, elems->function_name);

	//-------------------------------------------------------------------
	//Execute the OpenCL kernel on the list
	//
	//You can go into the function and change the size of a work group
	//
	//Send NDRANGE to this function
	exec_kernel(cl, elems->NDRANGE);

	//-------------------------------------------------------------------
	//Allocate memory for the local variable res and
	//read the memory buffer C on the device to the local variable res
	//
	//Go change this function to suit your needs
	res = read_buff(cl, elems->NDRANGE);
	return (res);
}
