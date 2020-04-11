#include "color.h"

//TODO sort this out

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
	r = gradient((START_COLOR >> 16) & 0xFF, (END_COLOR >> 16) & 0xFF, iter[i]);
	g = gradient((START_COLOR >> 8) & 0xFF, (END_COLOR >> 8) & 0xFF, iter[i]);
	b = gradient(START_COLOR & 0xFF, END_COLOR & 0xFF, iter[i]);

	t = *max_iter;
//	t = (float)iter / (float)max_iter;
//	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
//	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
//	b = (int)(8.5 * pow((1 - t), 3) * t * 255);

	color[i] = ((r << 16) | (g << 8) | b);
}