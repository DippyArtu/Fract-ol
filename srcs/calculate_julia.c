#include "fractol.h"

void			julia(t_fract *fract, t_cl *cl)
{
	t_elems		*elems;
	int 		*color;
	int 		i;
	//pthread_t 	thread;

	i = 0;
	elems = cl->items->elems;
	create_buffs(cl, elems, JULIA);
	exec_kernel(cl);
	exec_kernel_color(cl);
//	if (pthread_create(&thread, NULL, exec_kernel_color_multi, (void *)cl))
//	{
//		ft_putstr(THREAD_ERR);
//		exit(-1);
//	}
	color = read_buff(cl, elems->NDRANGE);
	while (i < (int)elems->NDRANGE)
	{
		put_pixel(fract, i, color[i]);
		i++;
	}
	mlx_do_sync(fract->mlx_ptr);
	cl_clean_mem_objs(cl);
	free(color);
}