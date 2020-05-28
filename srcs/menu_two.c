/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 22:20:12 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 22:32:29 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void 			buddha_menu(t_fract *fract)
{
	int		y;
	int		x;
	void	*mlx;
	void	*win;

	mlx = fract->mlx_ptr;
	win = fract->win_ptr;
	fill_background(fract);
	mlx_string_put(mlx, win, x = (B_WIDTH / 2) - 130,\
			y = (B_HEIGHT / 2) - 200, WHITE, "Press H to show this menu");
	mlx_string_put(mlx, win, x += 15, y += 30, WHITE, "or any key to close it");
	mlx_string_put(mlx, win, x += 10, y += 80, WHITE, "Available fractals:");
	mlx_string_put(mlx, win, x -= 100, y += 50, WHITE, "Mandelbrot set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "M");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Julia set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "J");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Calculate Buddhabrot set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "B");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Precalculated Buddhabrot set:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "C");
	mlx_string_put(mlx, win, x -= 350, y += 50, WHITE, "Exit:");
	mlx_string_put(mlx, win, x += 350, y, WHITE, "esc key");
}

void			print_menu_two(t_fract *fract, int type)
{
	if (type == BUDDHA || type == BUDDHA_PRECALC)
		buddha_menu(fract);
}