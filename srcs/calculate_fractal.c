//TODO only 1 row itteration is passed - why???

#include "fractol.h"

void		mandelbrot(t_mandel *mandel, t_fract *fract)
{
	int 	row;  // y coordinate
	int 	col;  // x coordinate
	int 	iter;

	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			map_to_zero(row, col, mandel);
			mandel->x = 0;
			mandel->y = 0;
			iter = 0;
			while ((sum_of_sqrs(mandel) <= 4) && iter < K_MAX)
			{
				find_p(mandel);
				iter++;
			}
			if (iter < K_MAX)
			{
				put_pixel(fract, col, row, WHITE); // P_k is not in the set
				//printf("WHITE @ %d, %d\n", col, row);
			}
			else
			{
				put_pixel(fract, col, row, BLACK); // P_k is in the set
				//printf("BLACK @ %d, %d\n", col, row);
			}
			col++;
		}
		row++;
	}
}