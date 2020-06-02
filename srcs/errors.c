/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:48:46 by Artur             #+#    #+#             */
/*   Updated: 2020/06/02 16:39:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		error(int type)
{
	if (type == 1)
	{
		ft_putstr(USAGE);
		ft_putstr(TYPES);
		ft_putstr(TYPES_T);
	}
	else if (type == 2)
		ft_putstr(INVALID);
	else if (type == 3)
		ft_putstr(MALLOC_ERR);
	else if (type == 4)
		ft_putstr(THREAD_ERR);
	exit(-1);
}
