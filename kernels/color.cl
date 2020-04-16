#include "color.h"

static float		gradient(float start, float end, float iter);
static void 		mode_1(int iter, global int *color, int i, float max_iter);
static void 		mode_2(int iter, global int *color, int i, float max_iter);
static void 		mode_3(int iter, global int *color, int i, float mu);

kernel void			vector_color(global int *iter, global int *color, constant t_color *color_s, global float *mu)
{
	int 			mode;
	int				i;
	private t_color	color_s_l;

	i = get_global_id(0);
	color_s_l = *color_s;

	mode = color_s_l.mode;
	switch(mode)
	{
		case 1: mode_1(iter[i], color, i, color_s_l.max_iter); break;
		case 2: mode_2(iter[i], color, i, color_s_l.max_iter); break;
		case 3: mode_3(iter[i], color, i, mu[i]); break;
		default: mode_1(iter[i], color, i, color_s_l.max_iter); break;
	}

}

static float		gradient(float start, float end, float iter)
{
	return (iter * start + iter * end);
}

static void 		mode_1(int iter, global int *color, int i, float max_iter)
{
	int				r;
	int				g;
	int				b;
	float			t;

	if (iter != -1)
	{
		t = (float)iter / max_iter;
		r = (int)(9 * (1 - t) * (t * t * t) * 255);
		g = (int)(15 * ((1 - t) * (1 - t)) * (t * t) * 255);
		b = (int)(8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255);
	}
	color[i] = (iter != -1) ? ((r << 16) | (g << 8) | b) : 0;
}

static void 		mode_2(int iter, global int *color, int i, float max_iter)
{
	int				r;
	int				g;
	int				b;
	float			t;

	if (iter != -1)
	{
		t = (float)iter / max_iter;
		r = (int)gradient((START_COLOR >> 16) & 0xFF, (END_COLOR >> 16) & 0xFF, iter);
		g = (int)gradient((START_COLOR >> 8) & 0xFF, (END_COLOR >> 8) & 0xFF, iter);
		b = (int)gradient(START_COLOR & 0xFF, END_COLOR & 0xFF, iter);
	}
	color[i] = (iter != -1) ? ((r << 16) | (g << 8) | b) : 0;
}

static void 		mode_3(int iter, global int *color, int i, float mu)
{
	int				r;
	int				g;
	int				b;
	float			one_log;
	float			three_sqr_two;
	float			sev_three_eighth;

	one_log = 1 / log((float)2);
	three_sqr_two = 1 / (3 * sqrt((float)2));
	sev_three_eighth = 1 / (7 * pow((float)3, (float)(1/8)));
	if (iter != -1)
	{
		r = (int)(255 * ((1 - cos((1 * one_log * mu)))) / 2);
		g = (int)(255 * ((1 - cos((three_sqr_two * one_log) * mu)) / 2));
		b = (int)(255 * ((1 - cos((sev_three_eighth * one_log) * mu)) / 2));
	}
	color[i] = (iter != -1) ? ((r << 16) | (g << 8) | b) : 0;
}


