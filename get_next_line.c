/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 08:06:13 by malberte          #+#    #+#             */
/*   Updated: 2018/05/03 01:11:48 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"

static int		fd_cmp(const void *fr1, const void *fr2)
{
	if (((t_file_reader*)fr1)->fd == ((t_file_reader*)fr2)->fd)
		return (0);
	return (1);
}

static t_list	*find_fd(const t_list *lst, int fd)
{
	t_file_reader to_find;

	to_find.fd = fd;
	return (ft_lstfind(lst, (void*)&to_find, &fd_cmp));
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_list;
	t_list			*fd_current;
	t_file_reader	file_reader;
	char			*tmp;
	t_file_reader	*r;
	ssize_t			bytes;
	
	bytes = -1;
	fd_current = find_fd(fd_list, fd);
	if (fd_current == NULL)
	{
		//init file reader
		file_reader.fd = fd;
		ft_bzero(file_reader.buffer, BUFF_SIZE);
		file_reader.buf_start = 0;
		file_reader.line = ft_strnew(BUFF_SIZE);
		file_reader.len = 0;
		file_reader.line_size = BUFF_SIZE;
		//add into list
		fd_current = ft_lstnew(&file_reader, sizeof(file_reader));
		ft_lstadd(&fd_list, fd_current);
	}
	r = (t_file_reader*)fd_current->content;
	r->line[0] = '\0';
	r->len = 0;
	while (r->buffer[r->buf_start] != '\n' && bytes != 0)
	{
		if (r->buffer[r->buf_start] == '\0')
		{
			ft_bzero(r->buffer, BUFF_SIZE);
			bytes = read(fd, r->buffer, BUFF_SIZE - 1);
			// if (bytes == 0)
			// {
			// 	break;
			// 	return (0);
			// }
			if (bytes == -1)
				return (-1);
			r->buf_start = 0;
		}
		if (r->len == r->line_size - 1)
		{
			//realloc line
			tmp = ft_strnew(r->line_size + BUFF_SIZE);
			ft_strcpy(tmp, *line);
			ft_strdel(line);
			*line = tmp;
		}
		r->line[r->len] = r->buffer[r->buf_start];
		++(r->len);
		++(r->buf_start);
	}
	r->line[r->len] = '\0';
	*line = ft_strdup(r->line);
	++(r->buf_start);
	if (bytes == 0)
		return (0);
	return (1);
}