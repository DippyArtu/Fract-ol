/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_buddhabrot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:32:52 by Artur             #+#    #+#             */
/*   Updated: 2020/06/02 16:39:24 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			buddhabrot_points(t_complex c,\
										int max_iter, t_complex *orbit)
{
	int				iter_c;
	t_complex		z;

	z = 0;
	cl_bzero(orbit, max_iter);
	iter_c = 0;
	while (iter_c < max_iter && cl_cmodsqr(z) < 4)
	{
		z = cl_cmult(z, z);
		z = cl_cadd(z, c);
		orbit[iter_c].x = cl_creal(z);
		orbit[iter_c].y = cl_cimag(z);
		iter_c++;
	}
	if (iter_c == max_iter)
		cl_bzero(orbit, max_iter);
}

/*
**  This function will collect a number of samples
**  (random numbers for C)
**
**  For each sample, calculate a list of points for which the function
**  escapes to infinity (if it does)
**
**  Then, map the points to the heatmap
*/

void				gen_heatmap(t_buddha *bud,\
								t_heatmap **map, t_heatmap *max_val)
{
	int				sample_i;
	t_complex		sample;
	t_complex		orbit[bud->max_iter];

	sample_i = 0;
	sample = 0;
	while (sample_i < bud->n_samples)
	{
		sample.x = get_rand(bud->re_min, bud->re_max);
		sample.y = get_rand(bud->im_min, bud->im_max);
		buddhabrot_points(sample, bud->max_iter, orbit);
		w_m(bud, orbit, map, max_val);
		sample_i++;
	}
}

/*
** This function writes the calculated
** Buddhabrot map in the file
**
** o - orbit
** mp - map
*/

void				w_m(t_buddha *b, t_complex *o,\
						t_heatmap **mp, t_heatmap *max)
{
	int			i;
	int			row;
	int			col;

	i = 0;
	while (i < b->max_iter)
	{
		if ((cl_creal(o[i]) != 0 && cl_cimag(o[i]) != 0) &&\
			(cl_creal(o[i]) <= b->re_max && cl_creal(o[i]) >= b->re_min &&\
			cl_cimag(o[i]) <= b->im_max && cl_cimag(o[i]) >= b->im_min))
		{
			row = row_from_real(cl_creal(o[i]), b);
			col = col_from_imag(cl_cimag(o[i]), b);
			mp[row][col] += 1;
			if (mp[row][col] > *max)
				*max = mp[row][col];
		}
		i++;
	}
}

void				buddhabrot(t_fract *fract)
{
	t_heatmap		**map;
	t_heatmap		max_heatmap_val;

	max_heatmap_val = 0;
	map = alloc_heatmap();
	gen_heatmap(fract->buddha, map, &max_heatmap_val);
	get_col_bud(fract, map, &max_heatmap_val);
	mlx_do_sync(fract->mlx_ptr);
}

void				get_col_bud(t_fract *fract,\
								t_heatmap **map, t_heatmap *m_val)
{
	int				row;
	int				col;
	int				i;
	int				*color;

	i = 0;
	row = 0;
	if (!(color = (int *)malloc(sizeof(int) * (B_HEIGHT * B_WIDTH))))
		error(3);
	while (row < B_HEIGHT)
	{
		col = 0;
		while (col < B_WIDTH)
		{
			map[row][col] = clr_htmp(map[row][col], *m_val, 255);
			color[i] = ((map[row][col] << 16) | (map[row][col] << 8)\
					| map[row][col]);
			i++;
			col++;
		}
		row++;
	}
	draw_buddha(fract, color);
	free_heatmap(map);
}
