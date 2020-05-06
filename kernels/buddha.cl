#include "buddhabrot.h"

static cl_complex	position(int x, int y, local t_buddha *bud, float width, float height);
static void 		buddhabrot_points(cl_complex c, int max_iter, cl_complex *orbit);
static int			row_from_real(float real, float re_min, float re_max, float height);
static int 			col_from_imag(float imag, float im_min, float im_max, float width);

kernel void			vector_buddha(global t_buddha *bud, global float *res)
{
	//int 			i;
	int				index;
//	int 			max_iter;
//	cl_complex 		c;
//	cl_complex 		orbit[50];
//	int 			row;
//	int 			col;
//	local t_buddha	bud_l;

	index = get_global_id(0);

	bud->orbits[index][0].x = 21;
	bud->orbits[index][0].y = 21;
	float outt = bud->orbits[index][0].x - bud->orbits[index][0].y;

	outt = bud->samples[0].x + bud->samples[0].y;
	res[index] = outt;

//	max_iter = bud->max_iter;
//	bud_l = *bud;
//	c = samples[index];
//
//	i = 0;
//	buddhabrot_points(c, max_iter, orbit);
}

static void 		buddhabrot_points(cl_complex c, int max_iter, cl_complex *orbit)
{
	int 			iter_c;
	cl_complex 		z = 0;

	cl_bzero(orbit, max_iter);
	iter_c = 0;
	while (iter_c < max_iter && cl_cmodsqr(z) < 4)
	{
		z = cl_cmult(z, z);
		z = cl_cadd(z, c);
		orbit[iter_c] = z;
		iter_c++;
	}
	if (iter_c == max_iter)
		cl_bzero(orbit, max_iter);
}

static int				row_from_real(float real, float re_min, float re_max, float height)
{
	return((int)((real - re_min) * (height / (re_max - re_min))));
}

static int 				col_from_imag(float imag, float im_min, float im_max, float width)
{
	return((int)((imag - im_min) * (width / (im_max - im_min))));
}

//---------------------------------------------------------------------------------------------------
//kernel void			vector_buddha(global int *color, global t_buddha *bud, global t_heatmap **heatmap)
//{
//	int 			tx;
//	int 			ty;
//	int 			index;
//	float 			x;
//	float 			y;
//	int 			iter_c;
//	int 			max_iter;
//	int 			min_iter;
//	float 			width;
//	float 			height;
//	cl_complex		c = 0;
//	cl_complex		z = 0; // value for iteration Z -> Z = Z * Z + C;
//
//	local t_buddha	bud_l;
//	bud_l = *bud;
//
//	tx = get_global_id(0);
//	ty = get_global_id(1);
//	width = get_global_size(0);
//	height = get_global_size(1);
//	index = ty * (int)width + tx;
//	max_iter = bud_l.max_iter;
//	min_iter = bud_l.min_iter;
//
//	x = (float)tx;
//	y = (float)ty;
//	iter_c = 0;
//	c = position(x, y, &bud_l, width, height);
//
//	while (cl_cmodsqr(z) <= 4 && iter_c < (int)max_iter)
//	{
//		z = cl_cmult(z, z);
//		z = cl_cadd(z, c);
//		iter_c++;
//	}
//	if (iter_c < max_iter && iter_c > min_iter)
//	{
//		color[index] = 0xffffff;
//	}
//}
//
//static cl_complex	position(int x, int y, local t_buddha *bud, float width, float height)
//{
//	float 		re_factor;
//	float 		im_factor;
//	cl_complex 	c;
//
//	re_factor = (bud->re_max - bud->re_min) / (width - 1);
//	im_factor = (bud->im_max - bud->im_min) / (height - 1);
//	bud->c_re = bud->re_min + x * re_factor;
//	bud->c_im = (bud->im_max - y * im_factor + 1) * -1;
//	c.x = bud->c_im * 1.1;
//	c.y = bud->c_re * 1.1;
//	return(c);
//}