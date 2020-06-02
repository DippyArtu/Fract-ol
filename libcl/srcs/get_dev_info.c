/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dev_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:46:52 by Artur             #+#    #+#             */
/*   Updated: 2020/06/02 16:39:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void		get_cl_info(t_cl *cl)
{
	t_cl_dev_info		*inf;

	inf = cl->dev_info;
	inf->platform_id = NULL;
	inf->device_id = NULL;
	inf->ret = clGetPlatformIDs(1, &inf->platform_id, &inf->num_platforms);
	if (inf->ret < 0)
	{
		ft_putstr(PLATFORM_ERR);
		exit(1);
	}
	inf->ret = clGetDeviceIDs(inf->platform_id, CL_DEVICE_TYPE_GPU,\
			128, &inf->device_id, &inf->num_devices);
	if (inf->ret < 0)
	{
		ft_putstr(DEVICE_ERR);
		exit(1);
	}
}

void		malloc_fail(void)
{
	ft_putstr("Memory allocation failed");
	exit(-1);
}
