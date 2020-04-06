#ifndef _FRACT_DEFINES_H
# define _FRACT_DEFINES_H

// 1400 * 800 desired resolution
# define WIDTH 800
# define HEIGHT 600

# define MANDEL_KERNEL_FILE "kernels/mandel_calc.cl"
# define MANDEL_KERNEL_FT "vector_mandel"

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

# define MANDEL 1

#endif
