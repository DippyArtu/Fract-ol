/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:50:02 by Artur             #+#    #+#             */
/*   Updated: 2020/06/08 17:32:06 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				fracts_menu(t_fract *fract)
{
	int				y;
	int				x;
	void			*mlx;
	void			*win;

	mlx = fract->mlx_ptr;
	win = fract->win_ptr;
	fill_background(fract);
	mlx_string_put(mlx, win, x = (WIDTH / 2) - 150,\
			y = (HEIGHT / 2) - 300, WHITE, "Available fractals:");
	mlx_string_put(mlx, win, x -= 100, y += 100, WHITE, "Mandelbrot set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "M");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Julia set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "J");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE,\
			"Calculate Buddhabrot set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "B");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE,\
			"Precalculated Buddhabrot set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "C");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Burning Ship set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "S");
}

static void			mandel_menu(t_fract *fract)
{
	int				y;
	int				x;
	void			*mlx;
	void			*win;

	mlx = fract->mlx_ptr;
	win = fract->win_ptr;
	fill_background(fract);
	mlx_string_put(mlx, win, x = (WIDTH / 2) - 150,\
			y = (HEIGHT / 2) - 300, WHITE, "Press H to show this menu");
	mlx_string_put(mlx, win, x += 15, y += 30, WHITE, "or any key to close it");
	mlx_string_put(mlx, win, x -= 40, y += 50, WHITE,\
				"Press TAB for available fractals");
	mlx_string_put(mlx, win, x -= 100, y += 70, WHITE, "Zoom In or Out:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Mouse wheel scroll");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Move:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Arrow keys");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Change color mode:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Keys 1-5");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Rotate light source");
	mlx_string_put(mlx, win, x, y += 20, WHITE, "in color mode 5:");
	mlx_string_put(mlx, win, x += 350, y -= 10, WHITE, "Keys +/-");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Exit:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "esc key");
}

static void			julia_menu(t_fract *fract)
{
	int				y;
	int				x;
	void			*mlx;
	void			*win;

	mlx = fract->mlx_ptr;
	win = fract->win_ptr;
	fill_background(fract);
	mlx_string_put(mlx, win, x = (WIDTH / 2) - 150,\
			y = (HEIGHT / 2) - 300, WHITE, "Press H to show this menu");
	mlx_string_put(mlx, win, x += 15, y += 30, WHITE, "or any key to close it");
	mlx_string_put(mlx, win, x -= 40, y += 50, WHITE,\
			"Press TAB for available fractals");
	mlx_string_put(mlx, win, x -= 115, y += 70, WHITE, "Set transform:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Mouse move or < >");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Zoom In or Out:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Mouse wheel scroll");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Move image:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Arrow keys");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Change color mode:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Keys 1-5");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Rotate light source");
	mlx_string_put(mlx, win, x, y += 20, WHITE, "in color mode 5:");
	mlx_string_put(mlx, win, x += 350, y -= 10, WHITE, "Keys +/-");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Exit:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "esc key");
}

static void			ship_menu(t_fract *fract)
{
	int				y;
	int				x;
	void			*mlx;
	void			*win;

	mlx = fract->mlx_ptr;
	win = fract->win_ptr;
	fill_background(fract);
	mlx_string_put(mlx, win, x = (WIDTH / 2) - 150,\
			y = (HEIGHT / 2) - 300, WHITE, "Press H to show this menu");
	mlx_string_put(mlx, win, x += 15, y += 30, WHITE, "or any key to close it");
	mlx_string_put(mlx, win, x -= 40, y += 50, WHITE,\
				"Press TAB for available fractals");
	mlx_string_put(mlx, win, x -= 100, y += 70, WHITE, "Zoom In or Out:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Mouse wheel scroll");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Move:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Arrow keys");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Change color mode:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "Keys 1-4");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Exit:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "esc key");
}

void				print_menu(t_fract *fract, int type)
{
	if (type == MANDEL)
		mandel_menu(fract);
	else if (type == JULIA)
		julia_menu(fract);
	else if (type == SHIP)
		ship_menu(fract);
	else
		print_menu_two(fract, type);
}
