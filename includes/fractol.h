#ifndef _FRACTOL_H
# define _FRACTOL_H

# ifndef LIBFT_H
#  include "libft.h"
# endif

# include "libcl.h"
# include "mlx.h"
# include <math.h>

# include "fract_defines.h"
# include "fract_structs.h"

# include <stdio.h>

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
	int 			iter_c;
	int 			cl_init;
	int 			menu_init;
	t_pos			*pos;
	t_color			*color;
	t_mandel		*mandel;
	t_julia			*julia;
	t_buddha		*buddha;
	t_mouse			*mouse;
	t_cl 			*cl;
}					t_fract;

t_fract			*init_fractol_struct(int type);
t_color 		*init_color(void);
t_fract 		*prep_fractal(int type);
void			draw(t_fract *fract, t_cl *cl, int type);
void			mandelbrot(t_fract *fract, t_cl *cl);
void			put_pixel(t_fract *fractal, int i, int color);
void			error(int type);
void			print_menu(t_fract *fract, int type);
void			shift_control(int key, t_fract *fract);
t_mouse			*init_mouse(void);
int				mouse_press(int key, int x, int y, void *p);
int				mouse_release(int key, int x, int y, void *p);
int 			mandel_mouse_pos(int x, int y, void *p);
float			interpolate(float start, float end, float interp);
void			apply_zoom(t_mandel *man, float m_re, float m_im, float interp);
void			zoom_in(t_fract *fract);
void			zoom_out(t_fract *fract);
void 			set_color(int key, t_fract *fract);
t_julia 		*init_julia(void);
t_mandel		*init_mandelbrot(void);
void 			draw_mandel(t_fract *fract, t_cl *cl);
void 			draw_julia(t_fract *fract, t_cl *cl);
void			julia(t_fract *fract, t_cl *cl);
int 			julia_mouse_move(int x, int y, void *p);
void 			julia_forward(t_fract *fract);
void 			julia_backward(t_fract *fract);
int				exit_prog(t_fract *fract);
void 			start(int type);
void 			set_fractal(int key, t_fract *fract);
void 			fracts_menu(t_fract *fract);
void 			fill_background(t_fract *fract);
void 			fractol_clean_up(t_fract *fract);
t_buddha 		*init_buddha(void);
void 			draw_buddha(t_fract *fract, t_cl *cl);
void 			buddhabrot(t_fract *fract, t_cl *cl);

#endif
