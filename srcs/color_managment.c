#include "fractol.h"

static int		gradient(int start, int end, int iter)
{
	return (iter * start + iter * end);
}

int				color(int iter, int max_iter)
{
	int			r;
	int			g;
	int			b;
	float 		t;


	r = gradient((START_COLOR >> 16) & 0xFF, (END_COLOR >> 16) & 0xFF, iter);
	g = gradient((START_COLOR >> 8) & 0xFF, (END_COLOR >> 8) & 0xFF, iter);
	b = gradient(START_COLOR & 0xFF, END_COLOR & 0xFF, iter);

	t = max_iter;
//	t = (float)iter / (float)max_iter;
//	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
//	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
//	b = (int)(8.5 * pow((1 - t), 3) * t * 255);

	return ((r << 16) | (g << 8) | b);
}