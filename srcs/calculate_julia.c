/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:48:31 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 15:48:31 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia(t_fract *fract, t_cl *cl)
{
	t_elems		*elems;
	int 		*color;
	int 		i;

	i = 0;
	elems = cl->items->elems;
	create_buffs(cl, elems, JULIA);
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
