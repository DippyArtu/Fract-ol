#include "fractol.h"

void 		set_color(int key, t_fract *fract)
{
	if (key == 18)
		fract->color->mode = 1;
	else if (key == 19)
		fract->color->mode = 2;
	else if (key == 20)
		fract->color->mode = 3;
	else if (key == 21)
		fract->color->mode = 4;
	else if (key == 23)
		fract->color->mode = 5;
	if (fract->color->mode == 5 && key == 24)
	{
		if (fract->color->angle < 360)
			fract->color->angle += 2;
		else if (fract->color->angle >= 360)
			fract->color->angle = 0;
	}
	if (fract->color->mode == 5 && key == 27)
	{
		if (fract->color->angle > 0)
			fract->color->angle -= 2;
		else if (fract->color->angle <= 0)
			fract->color->angle = 360;
	}
}