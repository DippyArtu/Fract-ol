#include "fractol.h"

static int		gradient(int start, int end, int iter)
{
	return (iter * start + iter * end);
}

int				color(int iter)
{
	int			r;
	int			g;
	int			b;


	r = gradient((START_COLOR >> 16) & 0xFF, (END_COLOR >> 16) & 0xFF, iter);
	g = gradient((START_COLOR >> 8) & 0xFF, (END_COLOR >> 8) & 0xFF, iter);
	b = gradient(START_COLOR & 0xFF, END_COLOR & 0xFF, iter);

	return ((r << 16) | (g << 8) | b);
}