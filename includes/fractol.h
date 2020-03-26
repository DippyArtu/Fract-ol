#ifndef _FRACTOL_H
# define _FRACTOL_H

# include "fract_defines.h"
# include "fract_structs.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <OpenCL/opencl.h>

# include <stdio.h>
# include <time.h>

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
void			zoom_in(t_fract *fract);
void			zoom_out(t_fract *fract);

#endif
