#include "fractol.h"

void		error(int type)
{
	if (type == 1)
	{
		ft_putstr(USAGE);
		ft_putstr(TYPES);
	}
	else if (type == 2)
		ft_putstr(INVALID);
	exit(1);
}