/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:32 by anpicard          #+#    #+#             */
/*   Updated: 2025/09/03 14:25:12 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "display.h"
#include "miniRT.h"
#include "vectors.h"

static int	parse_position(char *pos_str, t_vector *position);
static int	parse_orientation(char *orient_str, t_vector *orientation);
static int	add_values(char **line, t_display *display);

int	camera(char **line, int *camera_count, t_display *display)
{
	if (!line || !camera_count || !display)
		return (0);
	if (!line[0] || !line[1] || !line[2] || !line[3])
		return (0);
	if (line[4] != NULL)
		return (0);
	if (!coordinate_check(line[1]))
		return (0);
	if (!vector_orientation_check(line[2]))
		return (0);
	if (!fov_check(line[3]))
		return (0);
	(*camera_count)++;
	if (*camera_count > 1)
		return (0);
	if (!add_values(line, display))
		return (0);
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

static int	parse_orientation(char *orient_str, t_vector *orientation)
{
	char	**parts;

	parts = ft_split(orient_str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2])
	{
		if (parts)
			free_str(parts);
		return (0);
	}
	orientation->x = atof(parts[0]);
	orientation->y = atof(parts[1]);
	orientation->z = atof(parts[2]);
	free_str(parts);
	return (1);
}

static int	add_values(char **line, t_display *display)
{
	if (!parse_position(line[1], &display->camera.position))
		return (0);
	if (!parse_orientation(line[2], &display->camera.orientation))
		return (0);
	display->camera.orientation = normalize(display->camera.orientation);
	display->camera.fov = atoi(line[3]);
	return (1);
}
