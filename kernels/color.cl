#include "color.h"

static float		gradient(float start, float end, float iter)
{
	return (iter * start + iter * end);
}

kernel void			vector_color(global int *iter, global int *color, global float *max_iter)
{
	int			i;
	int			r;
	int			g;
	int			b;
	float 		t;

	i = get_global_id(0);
	t = iter[i] / *max_iter;
//	r = (int)gradient((START_COLOR >> 16) & 0xFF, (END_COLOR >> 16) & 0xFF, iter[i] * t);
//	g = (int)gradient((START_COLOR >> 8) & 0xFF, (END_COLOR >> 8) & 0xFF, iter[i] * t);
//	b = (int)gradient(START_COLOR & 0xFF, END_COLOR & 0xFF, iter[i] * t);

	r = (int)(9 * (1 - t) * (t * t * t) * 255);
	g = (int)(15 * ((1 - t) * (1 - t)) * (t * t) * 255);
	b = (int)(8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255);

	color[i] = ((r << 16) | (g << 8) | b);
}