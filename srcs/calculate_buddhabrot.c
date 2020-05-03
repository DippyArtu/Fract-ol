#include "fractol.h"

#include "cl_complex.h"

//TODO looks more like anti-buddhabrot, figure out how to return right orbits!
//TODO watch out for cl_complex.h!

static t_heatmap 	**alloc_heatmap(void)
{
	t_heatmap 		**map;
	int 			i;
	int 			j;

	i = 0;
	if (!(map = (t_heatmap **)malloc(HEIGHT * sizeof(t_heatmap *))))
		error(3);
	while (i < HEIGHT)
	{
		if (!(map[i] = (t_heatmap *)malloc(WIDTH * sizeof(t_heatmap))))
			error(3);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return(map);
}

static void 		free_heatmap(t_heatmap **map)
{
	int 			i;

	i = 0;
	while (i < HEIGHT)
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
	return((int)((real - bud->re_min) * (HEIGHT / (bud->re_max - bud->re_min))));
}

static int 				col_from_imag(float imag, t_buddha *bud)
{
	return((int)((imag - bud->im_min) * (WIDTH / (bud->im_max - bud->im_min))));
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

static float 			get_rand(float min, float max)
{
	float 			rand_n;

	sranddev();
	rand_n = rand() / (float) RAND_MAX;
	return(min + rand_n * (max - min));
}

static cl_complex 		*buddhabrot_points(cl_complex c, int max_iter)
{
	int 			iter_c;
	cl_complex 		z = 0;
	cl_complex 		*orbit;

	if (!(orbit = (cl_complex *)malloc(sizeof(cl_complex) * max_iter)))
		error(3);
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
	{
		cl_bzero(orbit, max_iter);
		return(orbit);
	}
	else
		return(orbit);
}

static void			gen_heatmap(t_heatmap **map, t_buddha *bud, t_heatmap *max_heatmap_val)
{
	int 			sample_i;

	cl_complex 		sample = 0;
	cl_complex 		*orbit;
	int 			i;
	int 			row;
	int 			col;

	sample_i = 0;
	while (sample_i < bud->n_samples)
	{
		sample.x = get_rand(bud->re_min, bud->re_max);
		sample.y = get_rand(bud->im_min, bud->im_max);
		orbit = buddhabrot_points(sample, bud->max_iter);
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
		free(orbit);
		sample_i++;
	}
}

static int			color_from_heatmap(t_heatmap heatmap_val, t_heatmap max_heatmap_val, float max_color)
{
	float 			scale;

	scale = (max_color / (float)max_heatmap_val);
	return((int)(heatmap_val * scale));
}

void 				buddhabrot(t_fract *fract, t_cl *cl)
{
	cl = NULL;

	t_heatmap		**map;
	t_heatmap 		max_heatmap_val;
	int 			row;
	int 			col;
	int 			i;
	int 			*color;
	int 			size = WIDTH * HEIGHT;

	if (!(color = (int *)malloc(sizeof(int) * size)))
		error(3);
	max_heatmap_val = 0;

	map = alloc_heatmap();

	gen_heatmap(map, fract->buddha, &max_heatmap_val);

	i = 0;
	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			map[row][col] = color_from_heatmap(map[row][col], max_heatmap_val, 255);
			color[i] = ((map[row][col] << 16) | (map[row][col] << 8) | map[row][col]);
			//printf("%i\n", color[i]);
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



//	t_elems		*elems;
//	int 		*color;
//	int 		i;
//
//	i = 0;
//	elems = cl->items->elems;
//	create_buffs(cl, elems, BUDDHA);
//	exec_kernel(cl);
//	color = read_buff(cl, elems->NDRANGE);
//	while (i < (int)elems->NDRANGE)
//	{
//		put_pixel(fract, i, color[i]);
//		i++;
//	}
//	mlx_do_sync(fract->mlx_ptr);
//	cl_clean_mem_objs(cl, fract->type);
//	free(color);
}
