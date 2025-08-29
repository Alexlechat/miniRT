/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:24:20 by allefran          #+#    #+#             */
/*   Updated: 2025/08/29 12:40:46 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "display.h"
# include "elements.h"
# include "objects.h"
# include <stdio.h>

typedef struct s_count
{
	int	light;
	int	camera;
	int	ambient;
}		t_count;

// -----------------------PARSING---------------------

int		parse_file(char *file_name, t_display *display);
int		validate_file(char *file_name);
int		bonus_check(char **line);
int		ambient(char **line, int *ambient_count, t_display *display);
int		light(char **line, int *light_count, t_display *display);
int		camera(char **line, int *camera_count, t_display *display);

// ------------------------UTILS-----------------------

int		is_valid_number(char *str);
char	**split_trimed(char *line);
int		parse_line(char *line, t_count *count, t_display *display);
int		parse_mandatory_elements(char *identifier, char **line_splited,
			int **counts, t_display *display);
int		parse_bonus_objects(char *identifier, char **line_splited);
int		check_consecutive_commas(char *str);
char	**split_and_validate_count(char *str);
int		ratio_check(char *str);
int		color_check(char *str);
int		coordinate_check(char *str);
int		vector_orientation_check(char *str);
int		fov_check(char *str);

void	free_str(char **str);
void	free_display(t_display *display);
char	*trim_newline(char *str);
int		print_error(char *str, int fd);

int		count_words(char **str);

#endif