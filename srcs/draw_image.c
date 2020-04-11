#include "fractol.h"

void			fill_background(t_fract *fract)
{
	int		i;
	int		*background;

	i = 0;
	background = (int *)fract->data_addr;
	while (i < WIDTH * HEIGHT)
	{
		background[i] = BLACK;
		i++;
	}
	background[i] = '\0';
}

void			put_pixel(t_fract *fractal, int i, int color)
{
	int		*pixel;

	pixel = (int *)(fractal->data_addr);

//	if (x > 0 && y > 0 && x < WIDTH && y < WIDTH)
//		pixel[x + (y * WIDTH)] = color;

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
			load_kernel_src_code(elems->kernel_name, cl);
			cl->items->elems = elems;
		}
		mandelbrot(fract, cl);
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
	print_menu(fract);
}