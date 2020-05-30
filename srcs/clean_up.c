/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:48:41 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 01:00:03 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 		fractol_clean_up(t_fract *fract)
{
	if (fract->mandel)
		free((void *)fract->mandel);
	else if (fract->julia)
		free((void *)fract->julia);
	else if (fract->buddha)
		free((void *)fract->buddha);
	else if (fract->ship)
		free((void *)fract->ship);
	if (fract->mouse)
		free((void *)fract->mouse);
	if (fract->pos)
		free((void *)fract->pos);
	if (fract->color)
		free((void *)fract->color);
	free((void *)fract);
}
