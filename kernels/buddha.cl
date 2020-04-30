#include "buddhabrot.h"

static cl_complex	position(int x, int y, local t_buddha *bud, float width, float height);

kernel void			vector_buddha(global int *color, global t_buddha *bud)
{
	int 			tx;
	int 			ty;
	int 			index;
	float 			x;
	float 			y;
	int 			iter_c;
	int 			max_iter;
	int 			min_iter;
	float 			width;
	float 			height;
	cl_complex		c = 0;
	cl_complex		z = 0; // value for iteration Z -> Z = Z * Z + C;

	local t_buddha	bud_l;
	bud_l = *bud;

	tx = get_global_id(0);
	ty = get_global_id(1);
	width = get_global_size(0);
	height = get_global_size(1);
	index = ty * (int)width + tx;
	max_iter = bud_l.max_iter;
	min_iter = bud_l.min_iter;

	x = (float)tx;
	y = (float)ty;
	iter_c = 0;
	c = position(x, y, &bud_l, width, height);

	while (cl_cmodsqr(z) <= 4 && iter_c < (int)max_iter)
	{
		z = cl_cmult(z, z);
		z = cl_cadd(z, c);
		iter_c++;
	}
	if (iter_c < max_iter && iter_c > min_iter)
	{
		color[index] = 0xffffff;
	}
}

static cl_complex	position(int x, int y, local t_buddha *bud, float width, float height)
{
	float 		re_factor;
	float 		im_factor;
	cl_complex 	c;

	re_factor = (bud->re_max - bud->re_min) / (width - 1);
	im_factor = (bud->im_max - bud->im_min) / (height - 1);
	bud->c_re = bud->re_min + x * re_factor;
	bud->c_im = (bud->im_max - y * im_factor + 1) * -1;
	c.x = bud->c_im * 1.1;
	c.y = bud->c_re * 1.1;
	return(c);
}