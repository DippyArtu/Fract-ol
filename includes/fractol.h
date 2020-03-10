#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# include <stdio.h>

# define WIDTH 100
# define HEIGHT 100

# define K_MAX 100 //maximum amount of iterations

# define BLACK 0x000000
# define WHITE 0xffffff

typedef struct 		s_mandelbrot
{
	double 		c_re;
	double 		c_im;
	double		x;
	double 		y;
	double 		x_new;
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
	t_mandel	*mandel;
}					t_fract;

t_fract			*init_fractol_struct(void);
void			draw(t_fract *fract);
void			mandelbrot(t_mandel *mandel, t_fract *fract);
void			map_to_zero(int row, int col, t_mandel *mandel);
int				sum_of_sqrs(t_mandel *mandel);
void			find_p(t_mandel *mandel);
void			put_pixel(t_fract *fractal, int x, int y, int color);

#endif
