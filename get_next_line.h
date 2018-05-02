/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 08:05:38 by malberte          #+#    #+#             */
/*   Updated: 2018/05/02 11:10:54 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# define BUFF_SIZE 32

typedef struct  s_file_reader
{
    int		fd;
    char	buffer[BUFF_SIZE];
	size_t	buf_start;
	char	*line;
	size_t	len;
	size_t	line_size;
}               t_file_reader;

int get_next_line(const int fd, char **line);

#endif