#ifndef _FRACT_DEFINES_H
# define _FRACT_DEFINES_H

# define WIDTH 1400
# define HEIGHT 1000

# define MANDEL_KERNEL_FILE "./kernels/mandel.cl"
# define COLOR_KERNEL_FILE "./kernels/color.cl"
# define COLOR_KERNEL_FT "vector_color"
# define MANDEL_KERNEL_FT "vector_mandel"
# define INC_PATH "-I ./kernel_includes"

# define Z_FACTOR 1.03

# define USAGE "Usage: ./fractol *type_of_fractal*\n"
# define TYPES "Available types:\n Mandelbrot\n"
# define INVALID "Invalid type given as an argument\n" TYPES
# define THREAD_ERR "Thread execution error\n"

//maximum  & initial amount of iterations
# define K_MAX 100000
# define K_START 500

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREY 0x5A5A5A

# define MANDEL 1

#endif
