#ifndef _COLOR_H
# define _COLOR_H

# include "cl_complex.cl"

# define BLACK 0x000000
# define RED 0xFF047A
# define DARK_GREEN 0xEAFC31

# define START_COLOR 0xBE04FF
# define END_COLOR 0x89FF04

typedef struct 		s_color
{
	float 			max_iter;
	int 			mode;
	float 			angle;
}					t_color;

#endif
