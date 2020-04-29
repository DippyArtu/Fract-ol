#include "fractol.h"

void 		fractol_clean_up(t_fract *fract)
{
	if (fract->mandel)
		free((void *)fract->mandel);
	else if (fract->julia)
		free((void *)fract->julia);
	else if (fract->buddha)
		free((void *)fract->buddha);
	if (fract->mouse)
		free((void *)fract->mouse);
	if (fract->pos)
		free((void *)fract->pos);
	if (fract->color)
		free((void *)fract->color);
	free((void *)fract);
}