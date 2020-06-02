/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fracts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:49:45 by Artur             #+#    #+#             */
/*   Updated: 2020/06/02 16:39:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mandel		*init_mandelbrot(void)
{
	t_mandel	*man;

	if (!(man = (t_mandel *)malloc(sizeof(t_mandel))))
		error(3);
	man->c_im = 0;
	man->c_re = 0;
	man->re_max = 2;
	man->re_min = -2;
	man->im_min = -2;
	man->im_max = man->im_min + (man->re_max - man->re_min) * HEIGHT / WIDTH;
	man->im_max_start = man->im_max;
	return (man);
}

t_julia			*init_julia(void)
{
	t_julia		*jul;

	if (!(jul = (t_julia *)malloc(sizeof(t_julia))))
		error(3);
	jul->k_re = (float)-0.4;
	jul->k_im = (float)0.6;
	return (jul);
}

t_buddha		*init_buddha(void)
{
	t_buddha	*bud;

	if (!(bud = (t_buddha *)malloc(sizeof(t_buddha))))
		error(3);
	bud->c_im = 0;
	bud->c_re = 0;
	bud->re_max = 2;
	bud->re_min = -2;
	bud->im_min = -2;
	bud->im_max = 2;
	bud->n_samples = B_WIDTH * B_HEIGHT;
	bud->width = B_WIDTH;
	bud->height = B_HEIGHT;
	bud->max_iter = 10;
	return (bud);
}

t_ship			*init_ship(void)
{
	t_ship		*ship;

	if (!(ship = (t_ship *)malloc(sizeof(t_ship))))
		error(3);
	ship->c_im = 0;
	ship->c_re = 0;
	ship->re_max = 2;
	ship->re_min = -2;
	ship->im_min = -2;
	ship->im_max = ship->im_min + (ship->re_max - ship->re_min)\
				* HEIGHT / WIDTH;
	ship->im_max_start = ship->im_max;
	return (ship);
}
