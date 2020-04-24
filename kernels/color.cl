#include "color.h"

static float		gradient(float start, float end, float iter);
static void 		mode_1(int iter, global int *color, int i, float max_iter);
static void 		mode_2(int iter, global int *color, int i, float max_iter);
static void 		mode_3(int iter, global int *color, int i, float mu);
static void 		mode_4(int iter, global int *color, int i, float mu);
static void 		mode_5(int iter, global int *color, int i, cl_complex z, cl_complex dc, float ang);

kernel void			vector_color(global int *iter,\
									global int *color,\
									constant t_color *color_s,\
									global float *mu,\
									global cl_complex *Z,\
									global cl_complex *dC)
{
	int 				mode;
	int					i;
	private t_color		color_s_l;
	private cl_complex	z; // value for iteration Z -> Z = Z * Z + C;
	private cl_complex	dc; // derivative with respect to c -> dC = 2.0 * dC * Z + 1.0;

	i = get_global_id(0);
	color_s_l = *color_s;
	z = Z[i];
	dc = dC[i];

	mode = color_s_l.mode;
	switch(mode)
	{
		case 1: mode_1(iter[i], color, i, color_s_l.max_iter); break;
		case 2: mode_2(iter[i], color, i, color_s_l.max_iter); break;
		case 3: mode_3(iter[i], color, i, mu[i]); break;
		case 4: mode_4(iter[i], color, i, mu[i]); break;
		case 5: mode_5(iter [i], color, i, z, dc, color_s_l.angle); break;
		default: mode_1(iter[i], color, i, color_s_l.max_iter); break;
	}
}

static float		gradient(float start, float end, float iter)
{
	return (iter * start + iter * end);
}

static void 		mode_5(int iter, global int *color, int i, cl_complex z, cl_complex dc, float ang)
{
	float			reflection = 0;
	unsigned int	b;

	float			h = (float)1.3; // height factor of the incoming light
	float			angle = (float)(ang / 360.0); // incoming direction of light
	cl_complex		v = 0; // = exp(1j*angle*2*pi/360)
	cl_complex		u = 0;
	cl_complex		u_tmp = 0;

	v.y = (2 * angle * Pi_cl);
	v = cl_cexp(v);

	if (iter != -1) // outside of M set
	{
		u = cl_cdiv(z, dc);
		u_tmp.x = cl_cmod(u);
		u = cl_cdiv(u, u_tmp);
		reflection = cl_cdot(u, v);
		reflection = reflection + h;
		reflection = (float)(reflection / (1.0 + h)); // rescale so that t does not get bigger than 1
	}
	b = (int)(255 * reflection);
	color[i] = (reflection <= 0) ? ((12 << 16) | (5 << 8) | 555) :\
			((b << 16) | (b << 8) | b);
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
		g = (int)(240 * ((1 - sin((three_sqr_two * one_log) * mu)) / 2));
		b = (int)(200 * ((1 - cos((sev_three_eighth * one_log) * mu)) / 2));
	}
	color[i] = (iter != -1) ? ((r << 16) | (g << 8) | b) : 0;
}

static void 		mode_4(int iter, global int *color, int i, float mu)
{
	int				r;
	int				g;
	int				b;

	if (iter != -1)
	{
		r = (int)(255 * ((1 + cos((float)(2 * Pi_cl * mu))) / 2));
		g = (int)(255 * ((1 + cos((float)(2 * Pi_cl * mu))) / 2));
		b = (int)(255 * ((1 + cos((float)(2 * Pi_cl * mu))) / 2));
	}
	color[i] = (iter != -1) ? ((r << 16) | (g << 8) | b) : 0;
}
