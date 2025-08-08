/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:35 by allefran          #+#    #+#             */
/*   Updated: 2025/08/08 13:50:31 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static int	parse_line(char *line, int *count_elements);
static char	**split_trimed(char *line);

int	parse_file(int argc, char *file_name)
{
	int		fd;
	char	*line;
	int		count_elements[3];

	count_elements[0] = 0;
	count_elements[1] = 0;
	count_elements[2] = 0;
	if (argc != 2)
		return (print_error("Usage : ./miniRT <scene.rt>\n", 2));
	if (!validate_file(file_name))
		return (print_error("Error\n", 2));
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		if (parse_line(line, count_elements) != 1)
			return (print_error("Error\n", 2));
		line = get_next_line(fd);
	}
	return (1);
}

static int	parse_line(char *line, int *count_elements)
{
	char	**line_splited;
	int		i;

	i = 0;
	line_splited = split_trimed(line);
	if (!line_splited)
		return (-1);
	if (line_splited[0] && ft_capital(line_splited[0][i]))
	{
		if (!mandatory_check(line_splited, count_elements))
			return (0);
	}
	return (1);
}

static char	**split_trimed(char *line)
{
	char	**trim_splited;
	char	**line_splited;
	int		i;

	line_splited = ft_split(line, ' ');
	trim_splited = malloc(sizeof(char *) * count_words(line_splited) + 1);
	if (!trim_splited)
		return (NULL);
	i = 0;
	while (line_splited[i])
	{
		trim_splited[i] = malloc(sizeof(char) * ft_strlen(line_splited[i]
					+ 1));
		if (!trim_splited[i])
		{
			free_all(trim_splited);
			return (NULL);
		}
		trim_splited[i] = trim_newline(line_splited[i]);
		i++;
	}
	trim_splited[i] = NULL;
	free_all(line_splited);
	return (trim_splited);
}
