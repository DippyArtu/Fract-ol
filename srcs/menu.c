#include "fractol.h"

static void 	fill_background(t_fract *fract)
{
	int 	*pixel;
	int 	i;

	i = 0;
	pixel = (int *)(fract->data_addr);
	while (i++ < HEIGHT * WIDTH)
		pixel[i] = BLACK;
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
}

void			print_menu(t_fract *fract)
{
	int		y;
	int		x;
	void	*mlx;
	void	*win;

	y = 0;
	x = 0;
	mlx = fract->mlx_ptr;
	win = fract->win_ptr;
	if (fract->color->mode == 1 || fract->color->mode == 2)
		mlx_string_put(mlx, win, x += 15, y += 15, GREY, "Menu: M");
	else
		mlx_string_put(mlx, win, x += 15, y += 15, BLACKISH, "Menu: M");
}

void 			menu(t_fract *fract)
{
	int		y;
	int		x;
	void	*mlx;
	void	*win;

	mlx = fract->mlx_ptr;
	win = fract->win_ptr;
	fill_background(fract);
	mlx_string_put(mlx, win, x = (WIDTH / 2) - 250,\
			y = (HEIGHT / 2) - 200, WHITE, "Zoom In or Out:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Mouse wheel scroll");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Move:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Arrow keys");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Change color mode:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Keys 1-5");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Rotate light source");
	mlx_string_put(mlx, win, x, y += 20, WHITE, "in color mode 5:");
	mlx_string_put(mlx, win, x += 350, y -= 10, WHITE, "Keys +/-");
	mlx_string_put(mlx, win, x -= 350, y += 60, WHITE, "Close menu:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Any key / Mouse press");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Exit:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "esc key");
}