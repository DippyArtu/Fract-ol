#include "fractol.h"

void 		set_color(int key, t_fract *fract)
{
	if (key == 18)
		fract->color->mode = 1;
	else if (key == 19)
		fract->color->mode = 2;
}