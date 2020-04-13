#include "color.h"

static void 		mode_1(int iter, global int *color, int i, float max_iter);
static void 		mode_2(int iter, global int *color, int i);

static float		gradient(float start, float end, float iter)
{
	return (iter * start + iter * end);
}

kernel void			vector_color(global int *iter, global int *color, constant t_color *color_s)
{
	int 			type;
	int				i;
	int				r;
	int				g;
	int				b;
	float 			t;
	int 			mode;
	local t_color	color_s_l;

	i = get_global_id(0);
	color_s_l = *color_s;

	mode = color_s_l.mode;
	if (mode == 1)
		mode_1(iter[i], color, i, color_s_l.max_iter);
	else if (mode ==2 )
		mode_2(iter[i], color, i);
}

static void 		mode_1(int iter, global int *color, int i, float max_iter)
{
	int				r;
	int				g;
	int				b;
	float			t;

	if (iter > -1)
	{
		t = (float)iter / max_iter;
		r = (int)(9 * (1 - t) * (t * t * t) * 255);
		g = (int)(15 * ((1 - t) * (1 - t)) * (t * t) * 255);
		b = (int)(8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255);
		color[i] = ((r << 16) | (g << 8) | b);
	}
	else
		color[i] = 0;
}

static void 		mode_2(int iter, global int *color, int i)
{
	int				r;
	int				g;
	int				b;

	if (iter > -1)
	{
		r = (int)gradient((START_COLOR >> 16) & 0xFF, (END_COLOR >> 16) & 0xFF, iter);
		g = (int)gradient((START_COLOR >> 8) & 0xFF, (END_COLOR >> 8) & 0xFF, iter);
		b = (int)gradient(START_COLOR & 0xFF, END_COLOR & 0xFF, iter);
		color[i] = ((r << 16) | (g << 8) | b);
	}
	else
		color[i] = 0;
}


