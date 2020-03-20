/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubptr_free.c           		                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:35:50 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 23:10:47 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsubptr_free(char *str, char const *ptr)
{
	char		*new;
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
	if (!(new = (char *)malloc(sizeof(char) * ((copy_c) + 1))))
		return (NULL);
	while (copy_c)
	{
		*new++ = *str++;
		copy_c--;
	}
	*new = '\0';
	ft_strdel(&str);
	return (new);
}