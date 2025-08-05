/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:34:33 by allefran          #+#    #+#             */
/*   Updated: 2025/08/05 20:31:14 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//Vérifie si le fichier contient du texte (n'est pas vide)
static int	check_file_not_empty(int fd)
{
	char	buffer[1];
	int		bytes_read;
	off_t	current_pos;

	current_pos = lseek(fd, 0, SEEK_CUR);
	if (current_pos == -1)
		return (0);
	bytes_read = read(fd, buffer, 1);
	if (bytes_read <= 0)
		return (0);
	if (lseek(fd, 0, SEEK_SET) == -1)
		return (0);
	return (1);
}

// Ouvre et valide le fichier
static int	open_and_validate_file(const char *filename)
{
	int	fd;

	if (!validate_rt_extension(filename))
	{
		ft_putstr_fd("Error: Invalid file extension. Expected .rt\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Cannot open file ", 2);
		ft_putstr_fd((char *)filename, 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	if (!check_file_not_empty(fd))
	{
		ft_putstr_fd("Error: File is empty\n", 2);
		close(fd);
		return (-1);
	}
	return (fd);
}

// Traite une ligne du fichier
static int	process_line(char *line, t_scene *scene, int line_count)
{
	if (line[0] == '\n' || line[0] == '#' || line[0] == '\0')
		return (1);
	if (!parse_line(line, scene))
	{
		ft_putstr_fd("Error: Invalid syntax at line ", 2);
		ft_putnbr_fd(line_count, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(line, 2);
		return (0);
	}
	return (1);
}

// Boucle principale de lecture du fichier
static int	read_file_loop(int fd, t_scene *scene, int *line_count)
{
	char	*line;
	int		result;

	result = 1;
	*line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		(*line_count)++;
		result = process_line(line, scene, *line_count);
		free(line);
		if (!result)
			break ;
		line = get_next_line(fd);
	}
	return (result);
}

//Parse un fichier .rt ligne par ligne avec get_next_line
int	parse_rt_file(const char *filename, t_scene *scene)
{
	int		fd;
	int		line_count;
	int		result;

	fd = open_and_validate_file(filename);
	if (fd == -1)
		return (0);
	init_scene(scene);
	result = read_file_loop(fd, scene, &line_count);
	close(fd);
	print_parse_result(line_count);
	if (line_count == 0)
		return (0);
	return (result);
}
