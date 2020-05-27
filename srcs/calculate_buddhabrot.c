#include "fractol.h"

static t_heatmap 			**alloc_heatmap(void) //heatmap = image size -- width * height
{
	t_heatmap 				**map;
	int 					i;
	int 					j;

	i = 0;
	if (!(map = (t_heatmap **)malloc(B_HEIGHT * sizeof(t_heatmap *))))
		error(3);
	while (i < B_HEIGHT)
	{
		if (!(map[i] = (t_heatmap *)malloc(B_WIDTH * sizeof(t_heatmap))))
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
	return(map);
}

static void 				free_heatmap(t_heatmap **map)
{
	int 					i;

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

static int				row_from_real(float real, t_buddha *bud)
{
	return((int)((real - bud->re_min) * (B_HEIGHT / (bud->re_max - bud->re_min))));
}

static int 				col_from_imag(float imag, t_buddha *bud)
{
	return((int)((imag - bud->im_min) * (B_WIDTH / (bud->im_max - bud->im_min))));
}

static void 		buddhabrot_points(t_complex c, int max_iter, t_complex *orbit)
{
	int 			iter_c;
	t_complex 		z = 0;

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
 *  This function will collect a number of samples
 *  (random numbers for C)
 *
 *  For each sample, calculate a list of points for which the function
 *  escapes to infinity (if it does)
 *
 *  Then, map the points to the heatmap
 */
static void			gen_heatmap(t_heatmap **map, t_buddha *bud, t_heatmap *max_heatmap_val)
{
	int 			sample_i;
	t_complex 		sample;
	t_complex 		orbit[bud->max_iter];
	int 			i;
	int 			row;
	int 			col;

	sample_i = 0;
	sample = 0;
	while (sample_i < bud->n_samples)
	{
		sample.x = get_rand(bud->re_min, bud->re_max);
		sample.y = get_rand(bud->im_min, bud->im_max);
		buddhabrot_points(sample, bud->max_iter, orbit);
		i = 0;
		while (i < bud->max_iter)
		{
			if ((cl_creal(orbit[i]) != 0 && cl_cimag(orbit[i]) != 0) &&\
			(cl_creal(orbit[i]) <= bud->re_max && cl_creal(orbit[i]) >= bud->re_min &&\
			cl_cimag(orbit[i]) <= bud->im_max && cl_cimag(orbit[i]) >= bud->im_min))
			{
				row = row_from_real(cl_creal(orbit[i]), bud);
				col = col_from_imag(cl_cimag(orbit[i]), bud);
				map[row][col] += 1;
				if (map[row][col] > *max_heatmap_val)
					*max_heatmap_val = map[row][col];
			}
			i++;
		}
		sample_i++;
	}
}

static int			color_from_heatmap(t_heatmap heatmap_val, t_heatmap max_heatmap_val, float max_color)
{
	float 			scale;

	scale = (max_color / (float)max_heatmap_val);
	return((int)(heatmap_val * scale));
}

void 				buddhabrot(t_fract *fract)
{
	t_heatmap		**map;
	t_heatmap 		max_heatmap_val;
	int 			*color;

	int 			row;
	int 			col;
	int 			i;
	int 			size;

	size = B_HEIGHT * B_WIDTH;
	if (!(color = (int *)malloc(sizeof(int) * size)))
		error(3);

	max_heatmap_val = 0;
	map = alloc_heatmap();

	gen_heatmap(map, fract->buddha, &max_heatmap_val);

	i = 0;
	row = 0;
	while (row < B_HEIGHT)
	{
		col = 0;
		while (col < B_WIDTH)
		{
			map[row][col] = color_from_heatmap(map[row][col], max_heatmap_val, 255);
			color[i] = ((map[row][col] << 16) | (map[row][col] << 8) | map[row][col]);
			i++;
			col++;
		}
		row++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(fract, i, color[i]);
		i++;
	}
	free(color);
	free_heatmap(map);
	mlx_do_sync(fract->mlx_ptr);
}
