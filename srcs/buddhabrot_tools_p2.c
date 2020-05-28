/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot_tools_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:36:50 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 15:36:50 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			color_from_heatmap(t_heatmap val, t_heatmap max_val, float max_color)
{
	float	scale;

	scale = (max_color / (float)max_val);
	return((int)(val * scale));
}