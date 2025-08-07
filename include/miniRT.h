/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:24:20 by allefran          #+#    #+#             */
/*   Updated: 2025/08/06 11:49:36 by allefran         ###   ########.fr       */
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
	t_plane		plane;
	t_sphere	sphere;
	t_cylinder	cylinder;
}				t_scene;

// -----------------------PARSING---------------------

int				parse_file(int argc, char *file_name);
int				validate_file_name(char *file_name);

// ------------------------UTILS-----------------------

int				print_error(char *str, int fd);
int				file_exist(char *file_name);

#endif