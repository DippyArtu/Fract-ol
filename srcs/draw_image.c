#include "fractol.h"

void			put_pixel(t_fract *fractal, int x, int y, int color)
{
	int		*pixel;

	pixel = (int *)(fractal->data_addr);
	//if (x > 0 && y > 0 && x < WIDTH && y < WIDTH)
	pixel[x + (y * WIDTH)] = color;
}

static void		fill_background(t_fract *fractol)
{
	int		i;
	int		*background;

	i = 0;
	background = (int *)fractol->data_addr;
	while (i < WIDTH * HEIGHT)
	{
		background[i] = BLACK;
		i++;
	}
	background[i] = '\0';
}

void		draw(t_fract *fract)
{
	fill_background(fract);
	mandelbrot(fract->mandel, fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
}