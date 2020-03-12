#include "fractol.h"

// time with single thread -> 0.119811

static int			key_press(int key, t_fract *fract)
{

	//printf("%d\n", key);

	if (key == 53)
		exit(0);
	else if (key == 24 || key == 27)
		zoom_control(key, fract);
	else if (key >= 123 && key <= 126)
		shift_control(key, fract);
	fill_background(fract);
	draw(fract, fract->type);
	return (0);
}

int 		main(int argc, char **argv)
{
	//-------timing----
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	//------------------

	t_fract		*fractol;
	int 		type;

	type = 0;
	if (argc != 2)
		error(1);
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		type = 1;
	if (type)
	{
		fractol = init_fractol_struct(1);
		draw(fractol, type);

		//-------timing----
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("%f\n", cpu_time_used);
		//------------------

		mlx_hook(fractol->win_ptr, 2, 0, key_press, fractol);
		mlx_hook(fractol->win_ptr, 4, 0, mouse_press, fractol);
		mlx_hook(fractol->win_ptr, 5, 0, mouse_release, fractol);
		mlx_loop(fractol->mlx_ptr);
	}
	else if(!type)
		error(2);

	return (0);
}