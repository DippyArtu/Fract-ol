#ifndef _FRACT_DEFINES_H
# define _FRACT_DEFINES_H

# define WIDTH 1400
# define HEIGHT 1000
# define B_WIDTH 500
# define B_HEIGHT 500

# define MANDEL_KERNEL_FILE "./kernels/mandel.cl"
# define MANDEL_KERNEL_FT "vector_mandel"

# define JULIA_KERNEL_FILE "./kernels/julia.cl"
# define JULIA_KERNEL_FT "vector_julia"

# define BUDDHA_KERNEL_FILE "./kernels/buddha.cl"
# define BUDDHA_KERNEL_FT "vector_buddha"

# define COLOR_KERNEL_FILE "./kernels/color.cl"
# define COLOR_KERNEL_FT "vector_color"

# define INC_PATH "-I ./kernel_includes"

# define Z_FACTOR 1.03

# define USAGE "Usage: ./fractol *type_of_fractal*\n"
# define TYPES "Available types:\n Mandelbrot\n Julia\n Buddhabrot\n"
# define INVALID "Invalid type given as an argument\n" TYPES
# define THREAD_ERR "Thread execution error\n"
# define MALLOC_ERR "Memory allocation has failed\n"

//maximum  & initial amount of iterations
# define K_MAX 100000
# define K_START 300

# define BLACK 0x000000
# define BLACKISH 0x151515
# define WHITE 0xFFFFFF
# define GREY 0x5A5A5A
# define PEACH 0xEEC1B0

# define MANDEL 1
# define JULIA 2
# define BUDDHA 3

#endif
