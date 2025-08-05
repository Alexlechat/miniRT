/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:22:14 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/05 19:51:32 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include "elements.h"

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
	int			num_spheres;
	int			num_planes;
	int			num_cylinders;
}			t_scene;

typedef struct s_minirt
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	t_scene	scene;
}			t_minirt;

/* Parsing */
int		parse_rt_file(const char *filename, t_scene *scene);
int		validate_rt_extension(const char *filename);
int		parse_line(char *line, t_scene *scene);
void	init_scene(t_scene *scene);
void	print_parse_result(int line_count);
void	free_split_array(char **split);
int		validate_rgb_values(int r, int g, int b);

/* Utils */
int		parse_vec3(char *str, t_vec3 *vec);
int		parse_color(char *str, t_color *color);
void	free_scene(t_scene *scene);
void	error_exit(const char *message);
double	ft_atof(const char *str);
void	print_scene_info(t_scene *scene);
char	**smart_split(char *line);
void	free_tokens(char **tokens);

#endif