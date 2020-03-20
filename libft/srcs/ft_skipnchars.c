/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipnchars.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:34:21 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/20 16:31:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_skipnchars(char *arr, size_t n)
{
	if (!arr || !n)
		return (NULL);
	while (n && arr)
	{
		arr++;
		n--;
	}
	return (arr);
}