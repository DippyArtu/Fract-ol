/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:37:29 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_newlen(char const *s)
{
	size_t		len;

	len = ft_strlen(s);
	while (*s == 32 || *s == 10 || *s == 9)
	{
		len--;
		s++;
	}
	while (*s != '\0')
		s++;
	s--;
	if (len)
		while (*s == 32 || *s == 10 || *s == 9)
		{
			len--;
			s--;
		}
	return (len);
}

char				*ft_strtrim(char const *s)
{
	size_t		len;
	char		*fresh;
	char		*out;

	if (s == NULL)
		return (NULL);
	len = ft_newlen(s);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (fresh == NULL)
		return (NULL);
	out = fresh;
	while (*s == 32 || *s == 10 || *s == 9)
		s++;
	while (len--)
		*fresh++ = *s++;
	*fresh = '\0';
	return (out);
}
