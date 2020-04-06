#ifndef _LIBCL_H_
# define _LIBCL_H_


# ifndef LIBFT_H
#  include "libft.h"
# endif

# include "cl_structs.h"
# include "cl_errors.h"

# define MAX_SOURCE_SIZE (0x100000)

t_cl		*init_opencl_structs(void);
void 		init_user_cl_structs(t_cl *cl);
t_elems		*init_opencl_elems(int NDR, char *k_name, char *ft_name, char *inc);
int 		*opencl_calc(t_cl *cl, t_elems *elems);
void 		load_kernel_src_code(char *kernel, t_cl *cl);
void 		get_cl_info(t_cl *cl);
void 		create_context_coms_queue(t_cl *cl);
void 		create_buffs(t_cl *cl, t_elems *elems, int type);
void 		cpy_to_buffs(t_cl *cl, int *re, int *im, int NDRANGE);
void 		prep_kernel(t_cl *cl, char *kernel_name, char *include);
void 		set_kernel_args(t_cl *cl);
void 		exec_kernel(t_cl *cl, int NDRANGE);
int 		*read_buff(t_cl *cl, int NDRANGE);
void 		cl_clean_up_all(t_cl *cl);
void 		cl_clean_up(t_cl *cl);
void 		cl_clean_mem_objs(t_cl *cl);
void 		cl_clean_structs(t_cl *cl, t_elems *elems);
void 		print_log(t_cl *cl);


#endif
