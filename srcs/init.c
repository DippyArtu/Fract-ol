#include "fractol.h"

t_color 	*init_color(void)
{
	t_color		*color;

	if (!(color = (t_color *)malloc(sizeof(t_color))))
		error(3);
	color->mode = 1;
	color->angle = 45;
	return(color);
}
t_mouse		*init_mouse(void)
{
	t_mouse		*mouse;

	if (!(mouse = (t_mouse *)malloc(sizeof(t_mouse))))
		error(3);
	mouse->press = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->Re = 0;
	mouse->Im = 0;
	return(mouse);
}

static	t_pos		*init_position(int type)
{
	t_pos	*pos;

	if (!(pos = (t_pos *)malloc(sizeof(t_pos))))
		error(3);
	if (type == MANDEL)
	{
		pos->shift_x = (float)-0.496;
		pos->shift_y = (float)0.496;
	}
	else
	{
		pos->shift_x = 0;
		pos->shift_y = 0;
	}
	pos->zoom = 1;
	pos->max_iter = K_START;
	return(pos);
}

static void 		init_rest(t_fract *fract, int type)
{
	fract->iter_c = 0;
	fract->pos = NULL;
	fract->color = NULL;
	fract->mouse = init_mouse();
	fract->mlx_ptr = mlx_init();
	if (type != BUDDHA)
	{
		fract->pos = init_position(type);
		fract->color = init_color();
		fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
		fract->image = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	}
	else if (type == BUDDHA)
	{
		fract->win_ptr = mlx_new_window(fract->mlx_ptr, B_WIDTH, B_HEIGHT, "Fract'ol");
		fract->image = mlx_new_image(fract->mlx_ptr, B_WIDTH, B_HEIGHT);
	}
	fract->data_addr = mlx_get_data_addr(fract->image, &fract->bpp, \
			&fract->size_line, &fract->endian);
	fract->cl_init = 0;
	fract->menu_init = 0;
}

t_fract				*init_fractol_struct(int type)
{
	t_fract 	*fractol;

	if (!(fractol = (t_fract *)malloc(sizeof(t_fract))))
		error(3);
	fractol->cl = NULL;
	fractol->mandel = NULL;
	fractol->julia = NULL;
	fractol->buddha = NULL;
	if (type == MANDEL)
	{
		fractol->mandel = init_mandelbrot();
		fractol->type = MANDEL;
	}
	else if (type == JULIA)
	{
		fractol->julia = init_julia();
		fractol->type = JULIA;
	}
	else if (type == BUDDHA)
	{
		fractol->buddha = init_buddha();
		fractol->type = BUDDHA;
	}
	init_rest(fractol, type);
	return(fractol);
}