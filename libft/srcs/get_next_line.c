/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:12:49 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/20 01:02:20 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_find_char(char *buff)
{
	size_t		position;

	position = 0;
	while (buff[position] != '\n' && buff[position] != '\0')
		position++;
	return (position);
}

static void		ft_update_buff(char *s1, const char *s2)
{
	int			i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	ft_bzero((void *)(&s1[i]), BUFF_SIZE - i);
}

static int		ft_write_line(char **line, char *buff, size_t nl_pos)
{
	if (buff[nl_pos] == '\n' || (buff[0] == '\0' && *line[0] != '\0'))
	{
		if (buff[nl_pos] == '\n')
			ft_update_buff(buff, &(buff[nl_pos + 1]));
		return (1);
	}
	return (0);
}

static char		*ft_strnjoin(char **line, const char *buff, size_t nl_pos)
{
	size_t		len;
	char		*line_new;
	char		*line_tmp;

	if (line == NULL || buff == NULL)
		return (NULL);
	line_tmp = *line;
	len = ft_strlen(line_tmp);
	if (!(line_new = ft_strnew(len + nl_pos + 1)))
		return (NULL);
	ft_memcpy(line_new, line_tmp, len);
	ft_memcpy(line_new + len, buff, nl_pos);
	free(line_tmp);
	return (line_new);
}

int				get_next_line(const int fd, char **line)
{
	size_t		nl_pos;
	int			ret;
	static char	buff[OPEN_MAX][BUFF_SIZE + 1];

	ret = 1;
	if (fd < 0 || !line || fd > OPEN_MAX)
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	while (ret > 0)
	{
		if (buff[fd][0] == '\0')
			if ((ret = read(fd, &buff[fd], BUFF_SIZE)) < 0)
				return (ret);
		nl_pos = ft_find_char(buff[fd]);
		*line = ft_strnjoin(line, buff[fd], nl_pos);
		if (ft_write_line(line, buff[fd], nl_pos))
			return (1);
		ft_strclr((char *)&buff[fd]);
	}
	return (0);
}
