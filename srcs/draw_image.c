#include "fractol.h"

//TODO return menu
void			draw(t_fract *fract, t_cl *cl, int type)
{
	type = 0;
	draw_buddha(fract, cl);
	mlx_clear_window(fract->mlx_ptr, fract->win_ptr);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
//	if (fract->menu_init)
//	{
//		if (type == MANDEL)
//			draw_mandel(fract, cl);
//		else if (type == JULIA)
//			draw_julia(fract, cl);
//		else if (type == BUDDHA)
//			draw_buddha(fract, cl);
//		mlx_clear_window(fract->mlx_ptr, fract->win_ptr);
//		mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
//	}
//	else
//	{
//		print_menu(fract, type);
//		fract->menu_init = 1;
//	}
}

void 			draw_buddha(t_fract *fract, t_cl *cl)
{
	t_elems		*elems;

	if (!fract->cl_init)
	{
		fract->cl_init = 1;
		elems = init_opencl_elems(BUDDHA_KERNEL_FILE,\
				BUDDHA_KERNEL_FT, INC_PATH);
		elems->buddha = fract->buddha;
		elems->color = NULL;
		load_kernel_src_code(elems->fract_kernel_name, cl);
		cl->items->elems = elems;
		prep_kernel(cl, elems->fract_ft_name, elems->include_flag);
	}
	buddhabrot(fract, cl);
}

void 			draw_julia(t_fract *fract, t_cl *cl)
{
	t_elems 	*elems;

	if (!fract->cl_init)
	{
		fract->cl_init = 1;
		elems = init_opencl_elems(JULIA_KERNEL_FILE,\
				JULIA_KERNEL_FT, INC_PATH);
		elems->julia = fract->julia;
		elems->color = fract->julia->color;
		elems->julia->pos = fract->pos;
		load_kernel_src_code(elems->fract_kernel_name, cl);
		cl->items->elems = elems;
		prep_kernel(cl, elems->fract_ft_name, elems->include_flag);
	}
	julia(fract, cl);
}

void 			draw_mandel(t_fract *fract, t_cl *cl)
{
	t_elems 	*elems;

	if (!fract->cl_init)
	{
		fract->cl_init = 1;
		elems = init_opencl_elems(MANDEL_KERNEL_FILE,\
				MANDEL_KERNEL_FT, INC_PATH);
		elems->mandel = fract->mandel;
		elems->color = fract->mandel->color;
		elems->mandel->pos = fract->pos;
		load_kernel_src_code(elems->fract_kernel_name, cl);
		cl->items->elems = elems;
		prep_kernel(cl, elems->fract_ft_name, elems->include_flag);
	}
	else
		mandelbrot(fract, cl);
}