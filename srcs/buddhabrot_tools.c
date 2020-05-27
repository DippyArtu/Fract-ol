#include "fractol.h"

float 						get_rand(float min, float max)
{
	float 					rand_n;

	sranddev();
	rand_n = rand() / (float) RAND_MAX;
	return(min + rand_n * (max - min));
}
