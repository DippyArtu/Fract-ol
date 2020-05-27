#include "fractol.h"

//TODO include -O3 optimization flag to makefiles

static int			key_press(int key, t_fract *fract)
{

	//printf("%d\n", key);

	if (fract->type != BUDDHA)
	{
		if (key >= 123 && key <= 126)
			shift_control(key, fract);
		else if ((key >= 18 && key <= 25) || key == 24 || key == 27)
			set_color(key, fract);
		draw(fract, fract->cl, fract->type);
		if (key == 4)
			print_menu(fract, fract->type);
		else if (key == 48)
			fracts_menu(fract);
		if (key == 38 || key == 46 || key == 11)
			set_fractal(key, fract);
	}
	if (key == 53)
		exit_prog(fract);
	return (0);
}

static void 		post_setup(t_fract *fractol, int type)
{
	if (type == MANDEL)
	{
		fractol->mandel->color = fractol->color;
		fractol->mandel->color->max_iter = fractol->pos->max_iter;
	}
	else if (type == JULIA)
	{
		fractol->julia->color = fractol->color;
		fractol->julia->color->max_iter = fractol->pos->max_iter;
	}
}

t_fract 			*prep_fractal(int type)
{
	t_fract		*fractol;
	t_cl		*cl;

	cl = NULL;
	fractol = init_fractol_struct(type);
	post_setup(fractol, type);
	if (type != BUDDHA)
	{
		cl = init_opencl_structs();
		fractol->cl = cl;
		get_cl_info(cl);
		create_context_coms_queue(cl);
	}
	draw(fractol, cl, type);
	return (fractol);
}

void 				start(int type)
{
	t_fract		*fractol;

	fractol = prep_fractal(type);
	mlx_hook(fractol->win_ptr, 2, 0, key_press, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->win_ptr, 5, 0, mouse_release, fractol);
	if (type == MANDEL)
		mlx_hook(fractol->win_ptr, 6, 0, mandel_mouse_pos, fractol);
	mlx_hook(fractol->win_ptr, 17, 1L << 17, exit_prog, fractol);
	mlx_loop(fractol->mlx_ptr);
}

int 				main(int argc, char **argv)
{
	int 		type;

	type = 0;
	if (argc != 2)
		error(1);
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		type = MANDEL;
	else if (!ft_strcmp(argv[1], "Julia"))
		type = JULIA;
	else if (!ft_strcmp(argv[1], "Buddhabrot"))
		type = BUDDHA;
	if(!type)
		error(2);
	start(type);
	return (0);
}