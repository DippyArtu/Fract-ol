#include "fractol.h"

static int			key_press(int key, t_fract *fract)
{

	//printf("%d\n", key);

	if (key >= 123 && key <= 126)
		shift_control(key, fract);
	fill_background(fract);
	draw(fract, fract->cl, fract->type);
	if (key == 53)
	{
		cl_clean_up_all(fract->cl);
		cl_clean_structs(fract->cl, fract->cl->items->elems);
		exit(0);
	}
	return (0);
}

int 		main(int argc, char **argv)
{
	t_fract		*fractol;
	t_cl		*cl;
	int 		type;

	type = 0;
	if (argc != 2)
		error(1);
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		type = MANDEL;
	if (type)
	{
		fractol = init_fractol_struct(type);
		cl = init_opencl_structs();
		fractol->cl = cl;
		get_cl_info(cl);
		create_context_coms_queue(cl);
		draw(fractol, cl, type);

		mlx_hook(fractol->win_ptr, 2, 0, key_press, fractol);
		mlx_hook(fractol->win_ptr, 4, 0, mouse_press, fractol);
		mlx_hook(fractol->win_ptr, 5, 0, mouse_release, fractol);
		mlx_hook(fractol->win_ptr, 6, 0, mouse_move, fractol);
		mlx_loop(fractol->mlx_ptr);
	}
	else if(!type)
		error(2);

	return (0);
}