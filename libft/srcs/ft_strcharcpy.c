/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:35:50 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/14 21:07:59 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcharcpy(char const *str1, char const *str2, char c)
{
	char		*str3;
	char		*tmp;
	size_t		str1_c;
	size_t		str2_c;

	str1_c = 0;
	str2_c = 0;
	if (!str1 || !str2 || !c)
		return (NULL);
	while (str1[str1_c])
		str1_c += 1;
	while (str2[str2_c] != c || str2[str2_c] != '\0')
		str2_c += 1;
	if (!(str3 = (char *)malloc(sizeof(char) * (str1_c + str2_c + 1))))
		return (NULL);
	tmp = str3;
	while (*str1 != '\0')
		*tmp++ = *str1++;
	while (*str2 != c)
		*tmp++ = *str2++;
	*tmp = '\0';
	return (str3);
}