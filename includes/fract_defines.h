#ifndef _FRACT_DEFINES_H
# define _FRACT_DEFINES_H

# define MAX_SOURCE_SIZE (0x100000)

// 1400 * 800 desired resolution
# define WIDTH 800
# define HEIGHT 600

# define Z_FACTOR 1.03

# define USAGE "Usage: ./fractol *type_of_fractal*\n"
# define TYPES "Available types:\n Mandelbrot\n"
# define INVALID "Invalid type given as an argument\n" TYPES

//maximum  & initial amount of iterations
# define K_MAX 2147483647
# define K_START 20

# define BLACK 0x000000
# define START_COLOR 0xBE04FF
# define END_COLOR 0x89FF04

#endif
