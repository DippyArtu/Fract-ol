#include "fractol.h"

void			put_pixel(t_fract *fractal, int i, int color)
{
	int		*pixel;

	pixel = (int *)(fractal->data_addr);
	pixel[i] = color;
}

void		draw(t_fract *fract, t_cl *cl, int type)
{
	t_elems *elems;

	if (type == MANDEL)
	{
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
		mandelbrot(fract, cl);
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
	print_menu(fract);
}