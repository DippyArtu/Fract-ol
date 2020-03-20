/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:30:02 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t			i;
	char			*out;
	unsigned int	buff;
	int				c;

	i = 1;
	c = n;
	while (c /= 10)
		i++;
	buff = n;
	if (n < 0)
	{
		buff = -n;
		i++;
	}
	if (!(out = ft_strnew(i)))
		return (NULL);
	out[--i] = buff % 10 + 48;
	while (buff /= 10)
		out[--i] = buff % 10 + 48;
	if (n < 0)
		*(out) = '-';
	return (out);
}
