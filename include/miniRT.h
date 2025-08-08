/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:24:20 by allefran          #+#    #+#             */
/*   Updated: 2025/08/08 15:05:24 by anpicard         ###   ########.fr       */
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

int				parse_file(int argc, char *file_name);
int				validate_file(char *file_name);
int				mandatory_check(char **line, int *count_elements);
int				bonus_check(char **line_splited);

// -------elements--------

int				light(char **line, int *l_count);
int				ambient(char **line, int *a_count);
int				camera(char **line, int *c_count);
// ------------------------UTILS-----------------------

int				ratio_check(char *str);
int				color_check(char *str);
int				coordinate_check(char *str);
int				vector_orientation_check(char *str);
int				fov_check(char *str);

void			free_all(char **str);
char			*trim_newline(char *str);
int				print_error(char *str, int fd);
int				is_number(char **line);
int				count_words(char **str);

#endif