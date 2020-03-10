/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:00:42 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/06 19:38:43 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcounter(char *str)
{
	int	i;
	int	counter;
	int	x;

	counter = 0;
	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			i++;
			x = 1;
		}
		if (x == 1)
		{
			counter++;
			x = 0;
		}
		if (str[i] != '\0')
			i++;
	}
	return (counter);
}
