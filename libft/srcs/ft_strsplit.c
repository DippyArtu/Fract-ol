/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:36:59 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_str_from_buff(char *arr, char *buff, size_t size)
{
	if (!(arr = ft_strnew(size + 1)))
	{
		free(arr);
		return (NULL);
	}
	arr = ft_strcpy(arr, buff);
	ft_bzero(buff, size);
	return (arr);
}

static char			**ft_fill_arr(const char *s, char c, char **arr, char *buff)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	while (*s)
	{
		counter = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			buff[counter] = *s;
			counter++;
			s++;
		}
		if (buff[0])
		{
			arr[i] = ft_str_from_buff(arr[i], buff, counter);
			i++;
		}
	}
	arr[i] = 0;
	return (arr);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	arr_i;
	char	**fresh;
	char	*buff;

	if (s == NULL)
		return (NULL);
	if (!(buff = ft_strnew(1000)))
	{
		free(buff);
		return (NULL);
	}
	arr_i = ft_strsplit_arrc(s, c);
	if (arr_i > (arr_i + 1))
		return (NULL);
	if (!(fresh = ft_arrnew(arr_i + 1)))
	{
		free(fresh);
		return (NULL);
	}
	fresh = ft_fill_arr(s, c, fresh, buff);
	free(buff);
	buff = NULL;
	return (fresh);
}
