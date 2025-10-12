/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:55:20 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/07 10:33:44 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "miniRT.h"
#include "vectors.h"

static int		parse_position(char *pos_str, t_vector *position);
static double	parse_vector(char *vector_str, t_vector *vector);
static int		parse_color(char *color_str, t_color *color);
static int		set_cylinder_values(char **line, t_display *display, int idx);

static int	set_cylinder_values(char **line, t_display *display, int idx)
{
	if (!parse_position(line[1], &display->cylinder[idx].position))
		return (0);
	if (!parse_vector(line[2], &display->cylinder[idx].orientation))
		return (0);
	display->cylinder[idx].orientation = normalize(
			display->cylinder[idx].orientation);
	display->cylinder[idx].radius = ft_atoi(line[3]) / 2;
	display->cylinder[idx].height = ft_atof(line[4]);
	if (!parse_color(line[5], &display->cylinder[idx].color))
		return (0);
	return (1);
}

int	add_values_cy(char **line, t_display *display)
{
	t_cylinder	*new_cylinders;
	int			current_index;

	new_cylinders = malloc(sizeof(t_cylinder) * (display->nb_cylinders + 1));
	if (!new_cylinders)
		return (0);
	if (display->cylinder && display->nb_cylinders > 0)
	{
		ft_memcpy(new_cylinders, display->cylinder, sizeof(t_cylinder)
			* display->nb_cylinders);
		free(display->cylinder);
	}
	display->cylinder = new_cylinders;
	current_index = display->nb_cylinders;
	if (!set_cylinder_values(line, display, current_index))
		return (0);
	display->nb_cylinders++;
	return (1);
}

static int	parse_position(char *pos_str, t_vector *position)
{
	char	**parts;

	parts = ft_split(pos_str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2])
	{
		if (parts)
			free_str(parts);
		return (0);
	}
	position->x = atof(parts[0]);
	position->y = atof(parts[1]);
	position->z = atof(parts[2]);
	free_str(parts);
	return (1);
}

static double	parse_vector(char *vector_str, t_vector *vector)
{
	char	**parts;

	parts = ft_split(vector_str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2])
	{
		if (parts)
			free_str(parts);
		return (0);
	}
	vector->x = atof(parts[0]);
	vector->y = atof(parts[1]);
	vector->z = atof(parts[2]);
	free_str(parts);
	return (1);
}

static int	parse_color(char *color_str, t_color *color)
{
	char	**parts;

	parts = ft_split(color_str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2])
	{
		if (parts)
			free_str(parts);
		return (0);
	}
	color->r = atoi(parts[0]);
	color->g = atoi(parts[1]);
	color->b = atoi(parts[2]);
	free_str(parts);
	return (1);
}
