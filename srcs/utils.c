/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:51:49 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 20:05:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			exit_prog(t_fract *fract)
{
	if (fract->type != BUDDHA && fract->type != BUDDHA_PRECALC)
	{
		cl_clean_up_all(fract->cl);
		cl_clean_structs(fract->cl, fract->cl->items->elems);
	}
	fractol_clean_up(fract);
	exit(0);
}

void		put_pixel(t_fract *fractal, int i, int color)
{
	int		*pixel;

	pixel = (int *)(fractal->data_addr);
	pixel[i] = color;
}

void		set_color(int key, t_fract *fract)
{
	if (key == 18)
		fract->color->mode = 1;
	else if (key == 19)
		fract->color->mode = 2;
	else if (key == 20)
		fract->color->mode = 3;
	else if (key == 21)
		fract->color->mode = 4;
	else if (fract->type != SHIP && key == 23)
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

void		set_fractal(int key, t_fract *fract)
{
	if (fract->type != BUDDHA && fract->type != BUDDHA_PRECALC)
	{
		cl_clean_up_all(fract->cl);
		cl_clean_structs(fract->cl, fract->cl->items->elems);
	}
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	fractol_clean_up(fract);
	if (key == 38)
		start(JULIA);
	else if (key == 46)
		start(MANDEL);
	else if (key == 11)
		start(BUDDHA);
	else if (key == 8)
		start(BUDDHA_PRECALC);
	else if (key == 1)
		start(SHIP);
}

void		fill_background(t_fract *fract)
{
	int		*pixel;
	int		i;

	i = 0;
	pixel = (int *)(fract->data_addr);
	if (fract->type != BUDDHA && fract->type != BUDDHA_PRECALC)
	{
		while (i++ < HEIGHT * WIDTH)
			pixel[i] = BLACK;
	}
	else if (fract->type == BUDDHA || fract->type == BUDDHA_PRECALC)
	{
		while (i++ < B_HEIGHT * B_WIDTH)
			pixel[i] = BLACK;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
	mlx_do_sync(fract->mlx_ptr);
}
