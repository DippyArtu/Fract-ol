/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:46:19 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 15:46:19 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBCL_H_
# define _LIBCL_H_

# ifndef LIBFT_H
#  include "libft.h"
# endif

# include <pthread.h>
# include "cl_structs.h"
# include "cl_errors.h"
# include "fract_defines.h"
# include "libcomplex.h"

//TODO remove stdio
#include <stdio.h>

# define MAX_SOURCE_SIZE (0x100000)

t_cl		*init_opencl_structs(void);
void 		init_user_cl_structs(t_cl *cl);
t_elems		*init_opencl_elems(char *k_name, char *ft_name, char *inc);
void 		load_kernel_src_code(char *kernel, t_cl *cl);
void 		get_cl_info(t_cl *cl);
void 		create_context_coms_queue(t_cl *cl);
void 		create_buffs(t_cl *cl, t_elems *elems, int type);
void 		cpy_to_buffs(t_cl *cl, int *re, int *im);
void 		prep_kernel(t_cl *cl, char *kernel_ft, char *include);
void 		create_program(t_cl *cl);
void 		build_program(t_cl *cl, char *include);
void 		set_kernel_args(t_cl *cl, int type);
void 		exec_kernel(t_cl *cl);
int 		*read_buff(t_cl *cl, size_t NDRANGE);
void 		cl_clean_up_all(t_cl *cl);
void 		cl_clean_mem_objs(t_cl *cl);
void 		cl_clean_structs(t_cl *cl, t_elems *elems);
void 		print_log(t_cl *cl, int type);
void 		exec_kernel_color(t_cl *cl);
void 		mandel_buffs(t_cl *cl, t_elems *elems);
void 		mandel_args(t_cl *cl);
void 		mandel_color_args(t_cl *cl);
void 		julia_buffs(t_cl *cl, t_elems *elems);
void 		julia_args(t_cl *cl);
void 		julia_color_args(t_cl *cl);
void 		malloc_fail(void);


#endif