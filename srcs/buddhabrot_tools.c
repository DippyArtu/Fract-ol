#include "fractol.h"

float 						get_rand(float min, float max)
{
	float 					rand_n;

	sranddev();
	rand_n = rand() / (float) RAND_MAX;
	return(min + rand_n * (max - min));
}

void 						*gen_samples(void *struc)
{
	t_buddha 				*bud;
	int 					lim;
	int 					start;
	static t_atomic_int 	count;
	int 					workload;

	bud = (t_buddha *)struc;
	workload = bud->n_samples / 500;
	__sync_fetch_and_add(&count, 1);
	start = workload * (count - 1);
	lim = start + workload;
	while (start < lim)
	{
		bud->samples[start].x = get_rand(bud->re_min, bud->re_max);
		bud->samples[start].y = get_rand(bud->im_min, bud->im_max);
		start++;
	}
	pthread_exit(NULL);
}

void 			init_b_samples(t_fract *fract, t_buddha *bud)
{
	int 		err;

	if (!(bud->samples = (t_complex *)malloc(sizeof(t_complex) * bud->n_samples)))
		error(3);
	if (!(fract->tid = (pthread_t *)malloc(500 * sizeof(pthread_t))))
		error(3);
	bud->thread_c = 0;
	while (bud->thread_c < 500)
	{
		err = pthread_create(&fract->tid[bud->thread_c], NULL, gen_samples, (void *)bud);
		if (err)
			error(4);
		bud->thread_c++;
	}
}

void 			join_threads(t_fract *fract)
{
	fract->buddha->thread_c = 0;
	while (fract->buddha->thread_c < 500)
	{
		pthread_join(fract->tid[fract->buddha->thread_c], NULL);
		fract->buddha->thread_c++;
	}
	free(fract->tid);
}

int				test_samples(t_fract *fract)
{
	int		test;
	int 	c;

	c = 0;
	while (c < fract->buddha->n_samples)
	{
		if (cl_creal(fract->buddha->samples[c]) == 0 && cl_cimag(fract->buddha->samples[c]) == 0)
		{
			test = c + 1;
			if (cl_creal(fract->buddha->samples[test]) == 0 && cl_cimag(fract->buddha->samples[test]) == 0)
			{
				test += 1;
				if (cl_creal(fract->buddha->samples[test]) == 0 && cl_cimag(fract->buddha->samples[test]) == 0)
				{
					ft_putstr("Sample generator failed at ");
					ft_putnbr(c);
					ft_putchar('\n');
					free(fract->buddha->samples);
					return(0);
				}
			}
		}
		c++;
	}
	return(1);
}