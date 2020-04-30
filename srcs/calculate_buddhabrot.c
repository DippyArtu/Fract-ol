#include "fractol.h"
#include <complex.h>

//TODO buddhabrot_points seg fault

static t_heatmap 	**alloc_heatmap(void)
{
	t_heatmap		**map;
	int 			i;
	int 			j;

	i = 0;
	j = 0;
	if (!(map = (t_heatmap **)malloc(sizeof(t_heatmap *) * HEIGHT)))
		error(3);
	while (i < HEIGHT)
	{
		if (!(map[i] = (t_heatmap *)malloc(sizeof(t_heatmap) * WIDTH)))
			error(3);
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

static float complex 		*buddhabrot_points(float complex c, int max_iter)
{
	int				n;
	float complex	z;
	float complex	*z_orbits;

	if (!(z_orbits = (float complex *)malloc(sizeof(float complex) * max_iter)))
		error(3);
	n = 0;
	z = 0;
	ft_bzero(z_orbits, max_iter);
	while (n < max_iter && cabs(z) <= 4)
	{
		z = z * z + c;
		z_orbits[n] = z;
		n++;
	}
	if (n == max_iter)
		return(NULL);
	else
		return(z_orbits);
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

static void 		gen_heatmap(t_heatmap **map, t_buddha *bud)
{
	int 			sample_i;
	float complex 	sample;
	float complex	*orbits;

	map = NULL;

	sample_i = 0;
	sample = (get_rand(bud->re_min, bud->re_max) +\
			get_rand(bud->im_min, bud->im_max) * I);
	while (sample_i < bud->n_samples)
	{
		sample = (get_rand(bud->re_min, bud->re_max) + get_rand(bud->im_min, bud->im_max) * I);
		orbits = buddhabrot_points(sample, bud->max_iter);
		//printf("%f+%fi\n", crealf(orbits[sample_i]), cimagf(orbits[sample_i]));
		sample_i++;
	}
}

void 				buddhabrot(t_fract *fract, t_cl *cl)
{
	cl = NULL;

	t_heatmap		**map;

	map = alloc_heatmap();
	printf("%i\n", map[0][0]);
	gen_heatmap(map, fract->buddha);
	free_heatmap(map);
	printf("All goot\n");
	exit(0);



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
