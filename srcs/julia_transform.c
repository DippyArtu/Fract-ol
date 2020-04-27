#include "fractol.h"

void 		julia_forward(t_fract *fract)
{
	fract->julia->k_re += (float)0.01;
	//fract->julia->k_im += (float)0.02;
}

void 		julia_backward(t_fract *fract)
{
	fract->julia->k_re -= (float)0.01;
	//fract->julia->k_im -= (float)0.02;
}