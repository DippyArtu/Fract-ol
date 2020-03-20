/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:36:06 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	size_t			len;
	char			*out;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = (size_t)ft_strlen(s);
	fresh = (char *)malloc(len * sizeof(char) + 1);
	if (fresh == NULL)
		return (NULL);
	*fresh = *ft_strcpy(fresh, s);
	out = fresh;
	i = 0;
	while (fresh[i])
	{
		fresh[i] = (*f)(i, fresh[i]);
		i++;
	}
	return (out);
}
