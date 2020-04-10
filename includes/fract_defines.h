#ifndef _FRACT_DEFINES_H
# define _FRACT_DEFINES_H

// 1400 * 1000 desired resolution
# define WIDTH 800
# define HEIGHT 600

# define MANDEL_KERNEL_FILE "./kernels/mandel.cl"
# define MANDEL_KERNEL_FT "vector_mandel"
# define INC_PATH "-I ./kernel_includes"

# define Z_FACTOR 1.03

# define USAGE "Usage: ./fractol *type_of_fractal*\n"
# define TYPES "Available types:\n Mandelbrot\n"
# define INVALID "Invalid type given as an argument\n" TYPES

//maximum  & initial amount of iterations
# define K_MAX 50000
# define K_START 50

# define BLACK 0x000000
# define START_COLOR 0xBE04FF
# define END_COLOR 0x89FF04

# define MANDEL 1

#endif
