#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# include <stdio.h>
# include <time.h>

# define WIDTH 500
# define HEIGHT 500

# define USAGE "Usage: ./fractol *type_of_fractal*\n"
# define TYPES "Available types:\n Mandelbrot\n"
# define INVALID "Invalid type given as an argument\n" TYPES

//maximum amount of iterations
# define K_MAX 1000

# define BLACK 0x000000
# define WHITE 0xffffff
# define START_COLOR 0xBE04FF
# define END_COLOR 0x89FF04

typedef struct 		s_position
{
	float  		zoom;
	float  		shift_x;
	float  		shift_y;
}					t_pos;

typedef struct 		s_mandelbrot
{
	float 		c_re;
	float  		c_im;
	float 		x;
	float  		y;
	float  		x_new;
	int 		max_iter;
	t_pos		*pos;
}					t_mandel;

typedef struct		s_fract
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int 		type;
	t_mandel	*mandel;
}					t_fract;

t_fract			*init_fractol_struct(int type);
void			draw(t_fract *fract, int type);
void			mandelbrot(t_mandel *mandel, t_fract *fract);
void			map_to_zero(int row, int col, t_mandel *mandel);
int				sum_of_sqrs(t_mandel *mandel);
void			find_p(t_mandel *mandel);
void			put_pixel(t_fract *fractal, int x, int y, int color);
int				color(int iter);
void			error(int type);
void			print_menu(t_fract *fract);
void			zoom_control(int key, t_fract *fract);
void			shift_control(int key, t_fract *fract);

#endif
