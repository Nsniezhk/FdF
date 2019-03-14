/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:49:11 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/06 14:32:14 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	t_list	*get_fd(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	return (tmp);
}

static	int		line_process(char *str, t_list *list, char **line)
{
	char	*tmp;
	char	*dup;
	int		len;
	int		c_len;

	tmp = ft_strdup(*line);
	ft_strdel(line);
	if (ft_strrchr(str, '\n'))
	{
		dup = ft_strndup(str, ft_strclen(str, '\n'));
		*line = ft_strjoin(tmp, dup);
		len = ft_strlen(str);
		c_len = ft_strclen(str, '\n');
		list->content = ft_strsub(str, c_len + 1, len - c_len);
		ft_strdel(&dup);
		ft_strdel(&str);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strjoin(tmp, str);
	ft_strclr(str);
	ft_strdel(&tmp);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	char			*buf;
	int				count;

	if (!line || fd < 0 || read(fd, 0, 0)
			|| !(*line = ft_strnew(0))
			|| !(buf = ft_strnew(BUFF_SIZE))
			|| !(file = get_fd(&file, fd)))
		return (-1);
	if (file->content && line_process(file->content, file, line))
		return (1);
	ft_memdel((void**)&file->content);
	while ((count = read(fd, buf, BUFF_SIZE)))
	{
		if (line_process(buf, file, line))
			return (1);
		if (count < BUFF_SIZE)
			break ;
	}
	ft_strdel(&buf);
	if (**line)
		return (1);
	file->content_size = 0;
	return (0);
}
