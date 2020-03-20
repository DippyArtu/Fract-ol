/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubptr.c               		                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:35:50 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsubptr(char const *str, char const *ptr)
{
	char		*str3;
	char		*tmp;
	size_t		str_c;
	size_t		ptr_c;
	size_t 		copy_c;

	str_c = 0;
	ptr_c = 0;
	if (!str)
		return (NULL);
	else if (!ptr)
		return ((char *)str);
	while (str[str_c])
		str_c += 1;
	while (ptr[ptr_c])
		ptr_c += 1;
	copy_c = str_c - ptr_c;
	if (!(str3 = (char *)malloc(sizeof(char) * ((copy_c) + 1))))
		return (NULL);
	tmp = str3;
	while (copy_c)
	{
		*tmp++ = *str++;
		copy_c--;
	}
	*tmp = '\0';
	return (str3);
}