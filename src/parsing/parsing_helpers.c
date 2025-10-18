/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apicard <apicard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:00 by apicard           #+#    #+#             */
/*   Updated: 2025/01/08 18:08:00 by apicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static char	**split_trimed(char *line);
static char	**allocate_trim_array(char **line_splited, int word_count);
static int	process_trimmed_words(char **line_splited, char **trim_splited);
static int	dispatch_parsing(char *id, char **line, int **c, t_display *d);

int	parse_line(char *line, t_count *count, t_display *display)
{
	char	**line_splited;
	int		*counts[3];

	counts[0] = &count->ambient;
	counts[1] = &count->light;
	counts[2] = &count->camera;
	line_splited = split_trimed(line);
	if (!line_splited)
		return (0);
	if (!line_splited[0])
	{
		free_str(line_splited);
		return (1);
	}
	return (dispatch_parsing(line_splited[0], line_splited, counts, display));
}

static int	dispatch_parsing(char *id, char **line, int **c, t_display *d)
{
	int	result;

	result = parse_mandatory_elements(id, line, c, d);
	if (result == -1)
		result = parse_bonus_objects(id, line, d);
	free_str(line);
	if (result == -1)
		return (print_error_msg("Invalid or unknown identifier "
				"in scene file\n"));
	return (result);
}

static char	**split_trimed(char *line)
{
	char	**trim_splited;
	char	**line_splited;
	int		word_count;

	if (!line)
		return (NULL);
	line_splited = ft_split(line, ' ');
	if (!line_splited)
		return (NULL);
	word_count = count_words(line_splited);
	trim_splited = allocate_trim_array(line_splited, word_count);
	if (!trim_splited)
		return (NULL);
	if (process_trimmed_words(line_splited, trim_splited) == -1)
	{
		free_str(trim_splited);
		free_str(line_splited);
		return (NULL);
	}
	free_str(line_splited);
	return (trim_splited);
}

static char	**allocate_trim_array(char **line_splited, int word_count)
{
	char	**trim_splited;

	trim_splited = malloc(sizeof(char *) * (word_count + 1));
	if (!trim_splited)
		free_str(line_splited);
	return (trim_splited);
}

static int	process_trimmed_words(char **line_splited, char **trim_splited)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line_splited[i])
	{
		trim_splited[j] = trim_newline(line_splited[i]);
		if (!trim_splited[j])
			return (-1);
		if (*trim_splited[j])
			j++;
		else
			free(trim_splited[j]);
		i++;
	}
	trim_splited[j] = NULL;
	return (0);
}
