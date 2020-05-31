/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 23:22:02 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 16:50:52 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BURNING_SHIP_H
# define _BURNING_SHIP_H

# include "cl_complex.h.cl"

typedef struct		s_position
{
	float			shift_x;
	float			shift_y;
	float			zoom;
	float			max_iter;
}					t_pos;

typedef struct		s_burning_ship
{
	float			c_re;
	float			c_im;
	float			re_min;
	float			re_max;
	float			im_min;
	float			im_max;
	float			im_max_start;
	t_pos			*pos;
}					t_ship;

#endif
