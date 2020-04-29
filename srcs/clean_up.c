#include "fractol.h"

void 		fractol_clean_up(t_fract *fract)
{
	if (fract->mandel)
		free((void *)fract->mandel);
	else if (fract->julia)
		free((void *)fract->julia);
	free((void *)fract->mouse);
	free((void *)fract->pos);
	free((void *)fract->color);
	free((void *)fract);
}