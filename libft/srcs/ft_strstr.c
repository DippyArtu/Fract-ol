/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:37:14 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *hay, const char *needle)
{
	int				hay_c;

	hay_c = 0;
	if (needle[0] == 0)
		return ((char *)hay);
	while (hay[hay_c])
	{
		while ((hay[hay_c] != needle[0]) && hay[hay_c])
			hay_c++;
		if (hay[hay_c])
		{
			if (ft_strstr_valid(hay, needle, hay_c) == 1)
				return ((char *)&hay[hay_c]);
			hay_c++;
		}
	}
	return (NULL);
}
