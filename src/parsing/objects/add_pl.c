/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:55:20 by anpicard          #+#    #+#             */
/*   Updated: 2025/09/30 13:29:38 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "miniRT.h"
#include "vectors.h"

static int	parse_position(char *pos_str, t_vector *position);
static int	parse_vector(char *vector_str, t_vector *vector);
static int	parse_color(char *color_str, t_color *color);

int	add_values_pl(char **line, t_display *display)
{
	t_plane	*new_planes;
	int		current_index;

	new_planes = malloc(sizeof(t_plane) * (display->nb_planes + 1));
	if (!new_planes)
		return (0);
	if (display->plane && display->nb_planes > 0)
	{
		ft_memcpy(new_planes, display->plane, sizeof(t_plane)
			* display->nb_planes);
		free(display->plane);
	}
	display->plane = new_planes;
	current_index = display->nb_planes;
	if (!parse_position(line[1], &display->plane[current_index].position))
		return (0);
	if (!parse_vector(line[2], &display->plane[current_index].orientation))
		return (0);
	display->plane[current_index].orientation = normalize(display->plane[current_index].orientation);
	if (!parse_color(line[3], &display->plane[current_index].color))
		return (0);
	display->nb_planes++;
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

static int	parse_vector(char *vector_str, t_vector *vector)
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
