/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:32:33 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 15:32:33 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw(t_fract *fract, t_cl *cl, int type)
{
	if (fract->menu_init || type == BUDDHA)
	{
		if (type == MANDEL)
			draw_mandel(fract, cl);
		else if (type == JULIA)
			draw_julia(fract, cl);
		else if (type == BUDDHA)
			buddhabrot(fract);
		mlx_clear_window(fract->mlx_ptr, fract->win_ptr);
		mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->image, 0, 0);
	}
	else
	{
		print_menu(fract, type);
		fract->menu_init = 1;
	}
}

void 			draw_julia(t_fract *fract, t_cl *cl)
{
	t_elems 	*elems;

	if (!fract->cl_init)
	{
		fract->cl_init = 1;
		elems = init_opencl_elems(JULIA_KERNEL_FILE,\
				JULIA_KERNEL_FT, INC_PATH);
		elems->julia = fract->julia;
		elems->color = fract->julia->color;
		elems->julia->pos = fract->pos;
		load_kernel_src_code(elems->fract_kernel_name, cl);
		cl->items->elems = elems;
		prep_kernel(cl, elems->fract_ft_name, elems->include_flag);
	}
	julia(fract, cl);
}

void 			draw_mandel(t_fract *fract, t_cl *cl)
{
	t_elems 	*elems;

	if (!fract->cl_init)
	{
		fract->cl_init = 1;
		elems = init_opencl_elems(MANDEL_KERNEL_FILE,\
				MANDEL_KERNEL_FT, INC_PATH);
		elems->mandel = fract->mandel;
		elems->color = fract->mandel->color;
		elems->mandel->pos = fract->pos;
		load_kernel_src_code(elems->fract_kernel_name, cl);
		cl->items->elems = elems;
		prep_kernel(cl, elems->fract_ft_name, elems->include_flag);
	}
	else
		mandelbrot(fract, cl);
}
