#include "fractol.h"

static t_mandel		*init_mandelbrot(void)
{
	t_mandel	*mandelbrot;

	mandelbrot = (t_mandel *)malloc(sizeof(t_mandel));
	mandelbrot->c_im = 0;
	mandelbrot->c_re = 0;
	mandelbrot->x = 0;
	mandelbrot->x_new = 0;
	mandelbrot->y = 0;
	return (mandelbrot);
}

t_fract				*init_fractol_struct(void)
{
	t_fract 	*fractol;

	fractol = (t_fract *) malloc(sizeof(t_fract));
	fractol->mandel = init_mandelbrot();
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	fractol->image = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->data_addr = mlx_get_data_addr(fractol->image, &fractol->bpp, \
			&fractol->size_line, &fractol->endian);
	return (fractol);
}