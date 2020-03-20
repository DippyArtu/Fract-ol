/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:34:08 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int i, int fd)
{
	if (i == MININT)
		write(fd, "-2147483648", 11);
	else
	{
		if (i < 0)
		{
			write(fd, "-", 1);
			i *= -1;
		}
		if (i > 9)
		{
			ft_putnbr_fd(i / 10, fd);
			ft_putnbr_fd(i % 10, fd);
		}
		else
		{
			i += 48;
			write(fd, &i, 1);
		}
	}
}
