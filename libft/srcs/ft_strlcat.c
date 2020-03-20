/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:35:54 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		x;
	size_t	total;

	i = 0;
	x = 0;
	i = ft_strlen(dst);
	total = (size_t)ft_strlen((char *)src);
	if (dstsize < (size_t)i)
		return (total + dstsize);
	total = (size_t)i + (size_t)ft_strlen((char *)src);
	dstsize -= (size_t)i;
	while (src[x] && dstsize > 1)
	{
		dst[i] = src[x];
		x++;
		i++;
		dstsize--;
	}
	ft_bzero(&dst[i], dstsize);
	return (total);
}
