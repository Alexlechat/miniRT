/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:35 by allefran          #+#    #+#             */
/*   Updated: 2025/09/03 14:35:39 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "miniRT.h"
#include "vectors.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int	process_file_lines(int fd, t_count *count, t_display *display);

int	parse_file(char *file_name, t_display *display)
{
	int		fd;
	t_count	count;

	count.ambient = 0;
	count.light = 0;
	count.camera = 0;
	if (!validate_file(file_name))
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!process_file_lines(fd, &count, display))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (count.ambient != 1 || count.camera != 1 || count.light != 1)
		return (0);
	calculate_focal(display);
	camera_offset(display);
	position_offset(display);
	return (1);
}

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
