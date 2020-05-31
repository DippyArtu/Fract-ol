/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:45:15 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 17:00:20 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MANDELBROT_H
# define _MANDELBROT_H

# include "cl_complex.h.cl"

typedef struct		s_position
{
	float			shift_x;
	float			shift_y;
	float			zoom;
	float			max_iter;
}					t_pos;

typedef struct		s_mandelbrot
{
	float			c_re;
	float			c_im;
	float			re_min;
	float			re_max;
	float			im_min;
	float			im_max;
	float			im_max_start;
	t_pos			*pos;
}					t_mandel;

#endif
