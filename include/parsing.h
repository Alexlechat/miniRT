/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:24:20 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 14:20:35 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "display.h"

typedef struct s_count
{
	int	light;
	int	camera;
	int	ambient;
}		t_count;

// -----------------------ELEMENTS---------------------
int		ambient(char **line, int *ambient_count, t_display *display);
int		camera(char **line, int *camera_count, t_display *display);
int		light(char **line, int *light_count, t_display *display);

// -----------------------OBJECTS---------------------
int		add_values_cy(char **line, t_display *display);
int		add_values_pl(char **line, t_display *display);
int		add_values_sp(char **line, t_display *display);
int		bonus_check(char **line, t_display *display);

// ------------------------UTILS-----------------------
int		coordinate_check(char *str);
int		vector_orientation_check(char *str);
int		color_check(char *str);
int		is_valid_number(char *str);
char	*trim_newline(char *str);

// -----------------------VALIDATION----------------------
int		check_consecutive_commas(char *str);
char	**split_and_validate_count(char *str);
int		fov_check(char *str);
int		ratio_check(char *str);

//---------------PARSING----------------
int		validate_file(char *file_name);
int		parse_mandatory_elements(char *identifier, char **line_splited,
			int **counts, t_display *display);
int		parse_bonus_objects(char *identifier, char **line_splited,
			t_display *display);
int		parse_line(char *line, t_count *count, t_display *display);
int		parse_file(char *file_name, t_display *display);

//---------------CORE_UTILS----------------
void	free_str(char **str);
void	free_display(t_display *display);
int		print_error(char *str, int fd);
int		print_error_msg(char *msg);
int		count_words(char **str);

#endif