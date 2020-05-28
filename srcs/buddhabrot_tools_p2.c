/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot_tools_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:36:50 by Artur             #+#    #+#             */
/*   Updated: 2020/05/28 21:21:05 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			color_from_heatmap(t_heatmap val, t_heatmap max_val, float max_color)
{
	float	scale;

	scale = (max_color / (float)max_val);
	return((int)(val * scale));
}

static void 				write_map_to_file(int *color, int size)
{
	int				fd;
	int				i;

	fd = open("buddha_map", O_WRONLY | O_CREAT | O_EXCL | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		remove("buddha_map");
		write_map_to_file(color, size);
	}
	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(color[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
	close(fd);
}

//TODO delete exit from here
void 				draw_buddha(t_fract *fract, int *color)
{
	int 			i;
	int 			size;

	size = B_HEIGHT * B_WIDTH;
	i = 0;
	write_map_to_file(color, size);
	while (i < size)
	{
		put_pixel(fract, i, color[i]);
		i++;
	}
	free(color);
}

void 				read_buddhabrot(t_fract *fract)
{
	int				fd;
	char 			*line;
	int				color;
	int				i;

	i = 0;
	fd = open("buddha_map", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		color = ft_atoi(line);
		free(line);
		put_pixel(fract, i, color);
		i++;
	}
	free(line);
	mlx_do_sync(fract->mlx_ptr);
}
