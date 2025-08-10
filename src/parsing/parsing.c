/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:35 by allefran          #+#    #+#             */
/*   Updated: 2025/08/08 18:26:04 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static int	process_file_lines(int fd, int *counts)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		if (parse_line(line, &counts[0], &counts[1], &counts[2]) != 1)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	parse_file(int argc, char *file_name)
{
	int		fd;
	int		counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	if (argc != 2)
		return (print_error("Usage : ./miniRT <scene.rt>\n", 2));
	if (!validate_file(file_name))
		return (print_error("Error\n", 2));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (print_error("Error\n", 2));
	if (!process_file_lines(fd, counts))
	{
		close(fd);
		return (print_error("Error\n", 2));
	}
	close(fd);
	if (counts[0] != 1 || counts[1] != 1 || counts[2] != 1)
		return (print_error("Error\n", 2));
	return (1);
}
