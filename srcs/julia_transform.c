/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:49:57 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 19:50:23 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_forward(t_fract *fract)
{
	static int		re_state;
	static int		im_state;

	if (fract->julia->k_re < -1 && !re_state)
		re_state = 1;
	else if (fract->julia->k_re > 1 && re_state)
		re_state = 0;
	if (!re_state)
		fract->julia->k_re -= (float)0.01;
	else if (re_state)
		fract->julia->k_re += (float)0.01;
	if (fract->julia->k_im > 1 && !im_state)
		im_state = 1;
	else if (fract->julia->k_im < -1 && im_state)
		im_state = 0;
	if (!im_state)
		fract->julia->k_im += (float)0.01;
	else if (im_state)
		fract->julia->k_im -= (float)0.01;
}

void		julia_backward(t_fract *fract)
{
	static int		re_state;
	static int		im_state;

	if (fract->julia->k_re < -1 && !re_state)
		re_state = 1;
	else if (fract->julia->k_re > 1 && re_state)
		re_state = 0;
	if (!re_state)
		fract->julia->k_re -= (float)0.01;
	else if (re_state)
		fract->julia->k_re += (float)0.01;
	if (fract->julia->k_im < -1 && !im_state)
		im_state = 1;
	else if (fract->julia->k_im > 1 && im_state)
		im_state = 0;
	if (!im_state)
		fract->julia->k_im -= (float)0.01;
	else if (im_state)
		fract->julia->k_im += (float)0.01;
}
