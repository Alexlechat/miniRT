/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:35 by allefran          #+#    #+#             */
/*   Updated: 2025/08/07 09:29:02 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "miniRT.h"
#include "libft/includes/libft.h"

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
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			i++;
		else if (ft_isalpha(line[i]))
		{
			/* code */
		}
		
		
		i++;
	}
	return (1);
}

int	is_identifier(char *line)
{
	int i;

	i = 0;
	while (line[])
	{
		/* code */
	}
	
}