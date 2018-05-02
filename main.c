/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:21:45 by malberte          #+#    #+#             */
/*   Updated: 2018/05/02 13:11:05 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;
	
	if (argc != 2)
	{
		printf("faut mettre un seul nom de fichier\n");
	}
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		printf("j'arrive pas a ouvrir le fichier\n");
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
	
	ft_strdel(&line);
	return (0);
}