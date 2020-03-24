#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# include <stdio.h>
# include <time.h>

// 1400 * 900 desired resolution

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

typedef struct	s_mouse
{
	int			press;
	double		x;
	double		y;
	double 		Re;
	double 		Im;
}				t_mouse;

typedef struct 		s_position
{
	double  		shift_x;
	double  		shift_y;
	double 			zoom;
}					t_pos;

typedef struct 		s_mandelbrot
{
	double 			c_re;
	double  		c_im;
	double 			x;
	double 			y;
	double 			x_sqr;
	double 			y_sqr;
	double 			re_min;
	double 			re_max;
	double 			im_min;
	double 			im_max;
	double 			im_max_start;
	t_pos			*pos;
}					t_mandel;

typedef struct		s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image;
	char			*data_addr;
	int				bpp;
	int				size_line;
	int				endian;
	int 			type;
	int 			itter_c;
	int 			max_iter;
	t_mandel		*mandel;
	t_mouse			*mouse;
}					t_fract;

t_fract			*init_fractol_struct(int type);
void			draw(t_fract *fract, int type);
void			mandelbrot(t_mandel *mandel, t_fract *fract);
void			position(int x, int y, t_mandel *mandel);
double			sqr_mod(t_mandel *mandel);
void			find_p(t_mandel *mandel);
void			put_pixel(t_fract *fractal, int x, int y, int color);
int				color(int iter, int max_iter);
void			error(int type);
void			print_menu(t_fract *fract);
void			zoom_control(int key, t_fract *fract);
void			shift_control(int key, t_fract *fract);
void			fill_background(t_fract *fract);
t_mouse			*init_mouse(void);
int				mouse_press(int key, int x, int y, void *p);
int				mouse_release(int key, int x, int y, void *p);
int 			mouse_move(int x, int y, void *p);
double			interpolate(double start, double end, double interp);
void			apply_zoom(t_mandel *man, double m_re, double m_im, double interp);

#endif
