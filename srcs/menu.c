#include "fractol.h"

void		print_menu(t_fract *fract)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fract->mlx_ptr;
	win = fract->win_ptr;
	mlx_string_put(mlx, win, 15, y += 15, BLACK, "Exit: esc");
}