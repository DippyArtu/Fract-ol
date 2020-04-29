#include "fractol.h"

int			exit_prog(t_fract *fract)
{
	cl_clean_up_all(fract->cl);
	cl_clean_structs(fract->cl, fract->cl->items->elems);
	fractol_clean_up(fract);
	exit(0);
}

void 		set_color(int key, t_fract *fract)
{
	if (key == 18)
		fract->color->mode = 1;
	else if (key == 19)
		fract->color->mode = 2;
	else if (key == 20)
		fract->color->mode = 3;
	else if (key == 21)
		fract->color->mode = 4;
	else if (key == 23)
		fract->color->mode = 5;
	if (fract->color->mode == 5 && key == 24)
	{
		if (fract->color->angle < 360)
			fract->color->angle += 2;
		else if (fract->color->angle >= 360)
			fract->color->angle = 0;
	}
	if (fract->color->mode == 5 && key == 27)
	{
		if (fract->color->angle > 0)
			fract->color->angle -= 2;
		else if (fract->color->angle <= 0)
			fract->color->angle = 360;
	}
}

void 		set_fractal(int key, t_fract *fract)
{
	cl_clean_up_all(fract->cl);
	cl_clean_structs(fract->cl, fract->cl->items->elems);
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	fractol_clean_up(fract);
	if (key == 38)
		start(JULIA);
	else if (key == 46)
		start(MANDEL);
}

void 		fill_background(t_fract *fract)
{
	int 	*pixel;
	int 	i;

	i = 0;
	pixel = (int *)(fract->data_addr);
	while (i++ < HEIGHT * WIDTH)
		pixel[i] = BLACK;
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
}

