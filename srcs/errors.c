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
	else if (type == 3)
		ft_putstr(MALLOC_ERR);
	exit(1);
}