/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:37:20 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/19 19:11:30 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strstr_valid(const char *h, const char *n, int hay_c)
{
	int needle_c;

	needle_c = 0;
	while (n[needle_c])
	{
		if (n[needle_c] != h[hay_c])
		{
			return (0);
		}
		else
		{
			hay_c++;
			needle_c++;
		}
	}
	return (1);
}
