#include "fractol.h"

int 		main(void)
{
	t_fract		*fractol;

	fractol = init_fractol_struct();
	draw(fractol);
	mlx_loop(fractol->mlx_ptr);
	return (0);
}