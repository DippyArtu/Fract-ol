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

void			put_pixel(t_fract *fractal, int x, int y, int color)
{
	int		*pixel;

	pixel = (int *)(fractal->data_addr);
	if (x > 0 && y > 0 && x < WIDTH && y < WIDTH)
		pixel[x + (y * WIDTH)] = color;
}

void		draw(t_fract *fract, int type)
{

	if (type == 1)
		mandelbrot(fract->mandel, fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
	print_menu(fract);
}