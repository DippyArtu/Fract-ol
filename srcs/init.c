#include "fractol.h"

static	t_pos		*init_position(void)
{
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->zoom = 1;
	pos->shift_x = 0;
	pos->shift_y = 0;
	return (pos);
}

static t_mandel		*init_mandelbrot(void)
{
	t_mandel	*man;

	man = (t_mandel *)malloc(sizeof(t_mandel));
	man->pos = init_position();
	man->c_im = 0;
	man->c_re = 0;
	man->x = 0;
	man->x_new = 0;
	man->y = 0;
	man->max_iter = 20;
	return (man);
}

t_fract				*init_fractol_struct(int type)
{
	t_fract 	*fractol;

	fractol = (t_fract *) malloc(sizeof(t_fract));
	if (type == 1)
	{
		fractol->mandel = init_mandelbrot();
		fractol->type = 1;
	}
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	fractol->image = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->data_addr = mlx_get_data_addr(fractol->image, &fractol->bpp, \
			&fractol->size_line, &fractol->endian);
	return (fractol);
}