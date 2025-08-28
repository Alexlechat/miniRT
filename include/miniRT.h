/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:24:20 by allefran          #+#    #+#             */
/*   Updated: 2025/08/28 17:13:51 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "elements.h"
# include "objects.h"
# include <stdio.h>

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
}				t_scene;

// -----------------------PARSING---------------------

int				parse_file(char *file_name);
int				validate_file(char *file_name);
int				bonus_check(char **line);
int				ambient(char **line, int *ambient_count);
int				light(char **line, int *light_count);
int				camera(char **line, int *camera_count);

// ------------------------UTILS-----------------------

int				is_valid_number(char *str);
char			**split_trimed(char *line);
int				parse_line(char *line, int *ambient_count,
					int *light_count, int *camera_count);
int				parse_mandatory_elements(char *identifier, char **line_splited,
					int **counts);
int				parse_bonus_objects(char *identifier, char **line_splited);
int				check_consecutive_commas(char *str);
char			**split_and_validate_count(char *str);
int				ratio_check(char *str);
int				color_check(char *str);
int				coordinate_check(char *str);
int				vector_orientation_check(char *str);
int				fov_check(char *str);

void			free_all(char **str);
char			*trim_newline(char *str);
int				print_error(char *str, int fd);

int				count_words(char **str);

#endif