/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:22 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/17 14:23:40 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"
#include "parsing.h"

static int	parse_position(char *pos_str, t_vector *position);
static int	parse_color(char *color_str, t_color *color);
static int	add_values(char **line, t_display *display);

int	light(char **line, int *light_count, t_display *display)
{
	if (!line || !light_count || !display)
		return (print_error_msg("Invalid light parameters\n"));
	if (!line[0] || !line[1] || !line[2] || !line[3])
		return (print_error_msg("Light: missing parameters\n"));
	if (line[4] != NULL)
		return (print_error_msg("Light: too many parameters\n"));
	if (!coordinate_check(line[1]))
		return (print_error_msg("Light: invalid position coordinates\n"));
	if (!ratio_check(line[2]))
		return (print_error_msg("Light: invalid brightness ratio\n"));
	if (!color_check(line[3]))
		return (print_error_msg("Light: invalid color format\n"));
	(*light_count)++;
	if (*light_count > 1)
		return (print_error_msg("Light: duplicate definition\n"));
	if (!add_values(line, display))
		return (print_error_msg("Light: failed to parse values\n"));
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

static int	add_values(char **line, t_display *display)
{
	if (!parse_position(line[1], &display->light.position))
		return (0);
	display->light.brightness = atof(line[2]);
	if (!parse_color(line[3], &display->light.color))
		return (0);
	return (1);
}
