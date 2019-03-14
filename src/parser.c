/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:55:28 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/04 12:55:30 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

/*
** CHECKING IS LINES IN FILE IS EQUAL
*/

static	int		file_line_check(char *file, t_point *p, int fd, int read)
{
	int		len;
	char	*line;

	len = -1;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	while (1)
	{
		read = get_next_line(fd, &line);
		if (read <= 0)
			break ;
		if (len == -1)
			len = ft_wordcount(line, ' ');
		if (ft_wordcount(line, ' ') != (size_t)len)
		{
			ft_strdel(&line);
			return (0);
		}
		p->y++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	p->x = len;
	return (1);
}

/*
** CHEKING IS FILE EMPTY OR NOT (THEN File_Line_Check();)
*/

int				file_check(char *file, t_point *p)
{
	int		fd;
	int		read;
	char	*line;

	read = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if ((read = get_next_line(fd, &line)) <= 0 || ft_wordcount(line, ' ') <= 1)
		return (0);
	ft_strdel(&line);
	close(fd);
	if (!(file_line_check(file, p, 0, 0)))
		return (0);
	return (1);
}
