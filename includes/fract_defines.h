/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:44:26 by Artur             #+#    #+#             */
/*   Updated: 2020/05/31 14:48:29 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACT_DEFINES_H
# define _FRACT_DEFINES_H

# define WIDTH 1400
# define HEIGHT 1000
# define B_WIDTH 900
# define B_HEIGHT 900

# define MANDEL_KERNEL_FILE "./kernels/mandel.cl"
# define MANDEL_KERNEL_FT "vector_mandel"

# define JULIA_KERNEL_FILE "./kernels/julia.cl"
# define JULIA_KERNEL_FT "vector_julia"

# define COLOR_KERNEL_FILE "./kernels/color.cl"
# define COLOR_KERNEL_FT "vector_color"

# define SHIPL_KERNEL_FILE "./kernels/ship.cl"
# define SHIP_KERNEL_FT "vector_ship"

# define INC_PATH "-I ./kernel_includes"

# define Z_FACTOR 1.03

# define USAGE "Usage: ./fractol *type_of_fractal*\n"
# define TYPES "Available types:\n Mandelbrot\n Julia\n"
# define TYPES_T " Buddhabrot\n Buddhabrot_precalc\n Burning_ship\n"
# define INVALID "Invalid type given as an argument\n" TYPES TYPES_T
# define THREAD_ERR "Thread execution error\n"
# define MALLOC_ERR "Memory allocation has failed\n"

/*
** Maximum and initial ammount of iterations
*/

# define K_MAX 100000
# define K_START 300

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define MANDEL 1
# define JULIA 2
# define BUDDHA 3
# define BUDDHA_PRECALC 4
# define SHIP 5

#endif
