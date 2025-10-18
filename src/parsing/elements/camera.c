/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:32 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/17 14:23:34 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"
#include "parsing.h"
#include "vectors.h"

static int	parse_position(char *pos_str, t_vector *position);
static int	parse_or(char *orient_str, t_vector *or);
static int	add_values(char **line, t_display *display);

int	camera(char **line, int *camera_count, t_display *display)
{
	if (!line || !camera_count || !display)
		return (print_error_msg("Invalid camera parameters\n"));
	if (!line[0] || !line[1] || !line[2] || !line[3])
		return (print_error_msg("Camera: missing parameters\n"));
	if (line[4] != NULL)
		return (print_error_msg("Camera: too many parameters\n"));
	if (!coordinate_check(line[1]))
		return (print_error_msg("Camera: invalid position coordinates\n"));
	if (!vector_orientation_check(line[2]))
		return (print_error_msg("Camera: invalid orientation vector\n"));
	if (!fov_check(line[3]))
		return (print_error_msg("Camera: invalid FOV (must be 0-180)\n"));
	(*camera_count)++;
	if (*camera_count > 1)
		return (print_error_msg("Camera: duplicate definition\n"));
	if (!add_values(line, display))
		return (print_error_msg("Camera: failed to parse values\n"));
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

static int	parse_or(char *orient_str, t_vector *or)
{
	char	**parts;

	parts = ft_split(orient_str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2])
	{
		if (parts)
			free_str(parts);
		return (0);
	}
	or->x = atof(parts[0]);
	or->y = atof(parts[1]);
	or->z = atof(parts[2]);
	free_str(parts);
	return (1);
}

static int	add_values(char **line, t_display *display)
{
	if (!parse_position(line[1], &display->camera.position))
		return (0);
	if (!parse_or(line[2], &display->camera.or))
		return (0);
	display->camera.or = normalize(display->camera.or);
	display->camera.fov = atoi(line[3]);
	return (1);
}
