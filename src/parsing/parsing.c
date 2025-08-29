/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:35 by allefran          #+#    #+#             */
/*   Updated: 2025/08/29 12:41:02 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "miniRT.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int	process_file_lines(int fd, t_count *count, t_display *display)
{
	char	*line;
	bool	parse_error;

	parse_error = false;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		if (parse_line(line, count, display) != 1)
			parse_error = true;
		free(line);
		line = get_next_line(fd);
	}
	if (parse_error)
	{
		free(line);
		free_display(display);
		return (0);
	}
	return (1);
}

int	parse_file(char *file_name, t_display *display)
{
	int		fd;
	t_count	count;

	count.ambient = 0;
	count.light = 0;
	count.camera = 0;
	if (!validate_file(file_name))
		return (print_error("Error\n", 2));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (print_error("Error\n", 2));
	if (!process_file_lines(fd, &count, display))
	{
		close(fd);
		return (print_error("Error\n", 2));
	}
	close(fd);
	if (count.ambient != 1 || count.camera != 1 || count.light != 1)
		return (print_error("Error\n", 2));
	return (1);
}
