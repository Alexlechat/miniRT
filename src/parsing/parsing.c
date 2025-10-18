/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:35 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 14:25:22 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "display.h"
#include "vectors.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

static int	process_file_lines(int fd, t_count *count, t_display *display);
static int	validate_mandatory_counts(t_count *count);

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
		return (print_error_msg("Failed to open file\n"));
	if (!process_file_lines(fd, &count, display))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!validate_mandatory_counts(&count))
		return (0);
	calculate_focal(display);
	camera_offset(display);
	position_offset(display);
	return (1);
}

static int	validate_mandatory_counts(t_count *count)
{
	if (count->ambient != 1)
		return (print_error_msg("Scene must have exactly one ambient light\n"));
	if (count->camera != 1)
		return (print_error_msg("Scene must have exactly one camera\n"));
	if (count->light != 1)
		return (print_error_msg("Scene must have exactly one light\n"));
	return (1);
}

static int	process_file_lines(int fd, t_count *count, t_display *display)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, count, display) != 1)
		{
			free(line);
			while (line)
			{
				line = get_next_line(fd);
				free(line);
			}
			free_display(display);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
