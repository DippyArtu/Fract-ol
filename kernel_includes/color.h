/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:45:02 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 17:06:13 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COLOR_H
# define _COLOR_H

# include "cl_complex.h.cl"

# define BLACK 0x000000

# define START_COLOR 0xBE04FF
# define END_COLOR 0x89FF04

typedef struct		s_color
{
	float			max_iter;
	int				mode;
	float			angle;
}					t_color;

#endif
