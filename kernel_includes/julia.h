/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:45:06 by Artur             #+#    #+#             */
/*   Updated: 2020/06/02 16:39:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _JULIA_H
# define _JULIA_H

# include "cl_complex.h.cl"

typedef struct		s_position
{
	float			shift_x;
	float			shift_y;
	float			zoom;
	float			max_iter;
}					t_pos;

typedef struct				s_julia
{
	float					k_re;
	float					k_im;
	t_pos					*pos;
}							t_julia;

#endif
