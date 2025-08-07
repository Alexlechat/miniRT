/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:35 by allefran          #+#    #+#             */
/*   Updated: 2025/08/07 14:40:19 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "miniRT.h"
#include "libft.h"

int	parse_file(int argc, char *file_name)
{
	int	fd;
	char *line;

	if (argc != 2)
		return(print_error("Usage : ./miniRT <scene.rt>\n", 2));
	if (!validate_file_name(file_name))
		return(print_error("Error\n", 2));
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		if (parse_line(line) != 1)
			return (print_error("Error\n", 2));
		line = get_next_line(fd);
	}
	
	return (1);
}


int	parse_line(char *line)
{
	char **line_splited;
	int i;

	i = 0;
	line_splited = ft_split(line, ' ');
	if (!line_splited)
		return (-1);
	if (line_splited[0] && ft_capital(line_splited[0][i]))
	{
		if(!mandatory_check(line_splited))
			return (0);
	}
	return (1);
}

