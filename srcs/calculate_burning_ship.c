/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_burning_ship.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 23:49:39 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 19:31:29 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			burning_ship(t_fract *fract, t_cl *cl)
{
	t_elems		*elems;
	int			*color;
	int			i;

	i = 0;
	elems = cl->items->elems;
	create_buffs(cl, elems, SHIP);
	exec_kernel(cl);
	exec_kernel_color(cl);
	color = read_buff(cl, elems->ndrange);
	while (i < (int)elems->ndrange)
	{
		put_pixel(fract, i, color[i]);
		i++;
	}
	mlx_do_sync(fract->mlx_ptr);
	cl_clean_mem_objs(cl);
	free(color);
}
