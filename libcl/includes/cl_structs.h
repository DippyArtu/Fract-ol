/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:46:08 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 17:06:13 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CL_STRUCTS_H
# define _CL_STRUCTS_H

# include <OpenCL/opencl.h>
# include <opencl-c-base.h>
# include "cl_user_structs.h"

typedef struct			s_cl_kernel_src
{
	int					fd_fract;
	int					fd_color;
	char				*fract_src_str;
	size_t				fract_src_size;
	char				*color_src_str;
	size_t				color_src_size;
}						t_cl_kernel_src;

typedef struct			s_cl_dev_info
{
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_uint				num_devices;
	cl_uint				num_platforms;
	cl_int				ret;
}						t_cl_dev_info;

typedef struct			s_cl_context
{
	cl_context			context;
	cl_command_queue	coms_queue;
	cl_program			program_fract;
	cl_program			program_color;
	cl_kernel			fract_kernel;
	cl_kernel			color_kernel;
}						t_cl_context;

typedef struct			s_cl
{
	t_cl_context		*context;
	t_cl_dev_info		*dev_info;
	t_cl_kernel_src		*kernel_src;
	t_cl_items			*items;
}						t_cl;

#endif
