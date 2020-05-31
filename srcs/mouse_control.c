/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:51:26 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 20:04:05 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						mouse_press(int key, int x, int y, void *p)
{
	t_fract				*fract;

	(void)x;
	(void)y;
	fract = (t_fract *)p;
	if ((fract->type == MANDEL || fract->type == SHIP) && key == 5)
		zoom_in(fract);
	else if ((fract->type == MANDEL || fract->type == SHIP) && key == 4)
		zoom_out(fract);
	else if (fract->type == JULIA && key == 5)
		julia_forward(fract);
	else if (fract->type == JULIA && key == 4)
		julia_backward(fract);
	if (fract->type == JULIA && key == 1)
	{
		fract->mouse->press = 1;
		mlx_hook(fract->win_ptr, 6, 0, julia_mouse_move, fract);
	}
	else if (key == 1)
		fract->mouse->press = 1;
	draw(fract, fract->cl, fract->type);
	return (0);
}

int						mouse_release(int key, int x, int y, void *p)
{
	t_fract				*fract;

	(void)x;
	(void)y;
	(void)key;
	fract = (t_fract *)p;
	fract->mouse->press = 0;
	return (0);
}

int						mandel_mouse_pos(int x, int y, void *p)
{
	t_fract				*fract;
	t_mandel			*man;
	float				re_factor;
	float				im_factor;

	fract = (t_fract *)p;
	man = fract->mandel;
	re_factor = (man->re_max - man->re_min) / (WIDTH - 1);
	im_factor = (man->im_max - man->im_min) / (HEIGHT - 1);
	fract->mouse->re = man->re_min + (float)x * re_factor;
	fract->mouse->im = man->im_max - (float)y * im_factor;
	return (0);
}

int						julia_mouse_move(int x, int y, void *p)
{
	t_fract				*fract;

	fract = (t_fract *)p;
	fract->julia->k_re = (float)(4 * ((float)x / WIDTH - 0.5));
	fract->julia->k_im = (float)(4 * ((float)(HEIGHT - y) / HEIGHT - 0.5));
	return (0);
}

int						ship_mouse_pos(int x, int y, void *p)
{
	t_fract				*fract;
	t_ship				*ship;
	float				re_factor;
	float				im_factor;

	fract = (t_fract *)p;
	ship = fract->ship;
	re_factor = (ship->re_max - ship->re_min) / (WIDTH - 1);
	im_factor = (ship->im_max - ship->im_min) / (HEIGHT - 1);
	fract->mouse->re = ship->re_min + (float)x * re_factor;
	fract->mouse->im = ship->im_max - (float)y * im_factor;
	return (0);
}
