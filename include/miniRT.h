/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:24:20 by allefran          #+#    #+#             */
/*   Updated: 2025/08/07 13:24:54 by anpicard         ###   ########.fr       */
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
int				validate_file_name(char *file_name);
int				mandatory_check(char **line);
int				parse_line(char *line);

// -------elements--------

int				light(char **line);
int				ambient(char **line);
int				camera(char **line);

// ------------------------UTILS-----------------------

int				print_error(char *str, int fd);
int				file_exist(char *file_name);
int				ratio_check(char *str);
int				is_number(char **line);
int				coordinate_check(char *str);
int				color_check(char *str);

#endif