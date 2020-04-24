#include "fractol.h"

t_color 	*init_color(void)
{
	t_color		*color;

	color = (t_color *)malloc(sizeof(t_color));
	color->mode = 1;
	color->angle = 45;
	return (color);
}
t_mouse		*init_mouse(void)
{
	t_mouse		*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	mouse->press = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->Re = 0;
	mouse->Im = 0;
	return (mouse);
}

static	t_pos		*init_position(void)
{
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->shift_x = (float)-0.496;
	pos->shift_y = (float)0.496;
	pos->zoom = 1;
	pos->max_iter = K_START;
	return (pos);
}

static t_mandel		*init_mandelbrot(void)
{
	t_mandel	*man;

	man = (t_mandel *)malloc(sizeof(t_mandel));
	man->c_im = 0;
	man->c_re = 0;
	man->re_max = 2;
	man->re_min = -2;
	man->im_min = -2;
	man->im_max = man->im_min + (man->re_max - man->re_min) * HEIGHT / WIDTH;
	man->im_max_start = man->im_max;
	return (man);
}

t_fract				*init_fractol_struct(int type)
{
	t_fract 	*fractol;

	fractol = (t_fract *)malloc(sizeof(t_fract));
	if (type == MANDEL)
	{
		fractol->mandel = init_mandelbrot();
		fractol->type = MANDEL;
	}
	fractol->iter_c = 0;
	fractol->mouse = init_mouse();
	fractol->pos = init_position();
	fractol->color = init_color();
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	fractol->image = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->data_addr = mlx_get_data_addr(fractol->image, &fractol->bpp, \
			&fractol->size_line, &fractol->endian);
	fractol->cl_init = 0;
	return (fractol);
}