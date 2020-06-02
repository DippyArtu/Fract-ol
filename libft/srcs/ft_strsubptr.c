/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 18:42:03 by Artur             #+#    #+#             */
/*   Updated: 2020/06/02 16:39:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copy_str(size_t copy_c, char *tmp, char const *str)
{
	while (copy_c)
	{
		*tmp++ = *str++;
		copy_c--;
	}
	*tmp = '\0';
	return (tmp);
}

char			*ft_strsubptr(char const *str, char const *ptr)
{
	char		*str3;
	char		*tmp;
	size_t		str_c;
	size_t		ptr_c;
	size_t		copy_c;

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
	tmp = copy_str(copy_c, tmp, str);
	return (str3);
}
