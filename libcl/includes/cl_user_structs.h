/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_user_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:46:13 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 17:11:32 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CL_USER_STRUCTS_H
# define _CL_USER_STRUCTS_H

# include "fract_structs.h"

typedef struct		s_elements
{
	size_t			ndrange;
	size_t			global_ws[2];
	size_t			local_ws[2];
	size_t			color_local_ws;
	char			*fract_kernel_name;
	char			*fract_ft_name;
	char			*include_flag;
	t_mandel		*mandel;
	t_julia			*julia;
	t_color			*color;
	t_ship			*ship;
}					t_elems;

typedef struct		s_cl_items
{
	t_elems			*elems;
	cl_mem			iter_mem_obj;
	cl_mem			mu_mem_obj;
	cl_mem			color_struct_mem_obj;
	cl_mem			color_mem_obj;
	cl_mem			pos_mem_obj;
	cl_mem			fract_mem_obj;
	cl_mem			z_mem_obj;
	cl_mem			dc_mem_obj;
}					t_cl_items;

#endif
