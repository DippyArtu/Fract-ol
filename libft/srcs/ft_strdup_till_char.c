/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_till_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:35:50 by jsalome           #+#    #+#             */
/*   Updated: 2020/05/31 18:47:58 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup_till_char(char const *str, char c)
{
	char		*new;
	char		*tmp;
	size_t		str_c;

	str_c = 0;
	if (!str || !c)
		return (NULL);
	while (str[str_c] != c)
		str_c += 1;
	if (!(new = (char *)malloc(sizeof(char) * (str_c + 1))))
		return (NULL);
	tmp = new;
	while (*str != c)
		*tmp++ = *str++;
	*tmp = '\0';
	return (new);
}
