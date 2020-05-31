/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 18:52:44 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 20:17:11 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float			get_rand(float min, float max)
{
	float		rand_n;

	sranddev();
	rand_n = rand() / (float)RAND_MAX;
	return (min + rand_n * (max - min));
}

t_heatmap		**alloc_heatmap(void)
{
	t_heatmap	**map;
	int			i;
	int			j;

	i = 0;
	if (!(map = (t_heatmap **)malloc(sizeof(t_heatmap *) * B_HEIGHT)))
		error(3);
	while (i < B_HEIGHT)
	{
		if (!(map[i] = (t_heatmap *)malloc(sizeof(t_heatmap) * B_WIDTH)))
			error(3);
		i++;
	}
	i = 0;
	while (i < B_HEIGHT)
	{
		j = 0;
		while (j < B_WIDTH)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void			free_heatmap(t_heatmap **map)
{
	int			i;

	i = 0;
	while (i < B_HEIGHT)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int				row_from_real(float real, t_buddha *bud)
{
	return ((int)((real - bud->re_min)\
				* (B_HEIGHT / (bud->re_max - bud->re_min))));
}

int				col_from_imag(float imag, t_buddha *bud)
{
	return ((int)((imag - bud->im_min)\
				* (B_WIDTH / (bud->im_max - bud->im_min))));
}
