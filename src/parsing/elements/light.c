/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:22 by anpicard          #+#    #+#             */
/*   Updated: 2025/09/03 14:06:27 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "display.h"
#include "miniRT.h"

static int	parse_position(char *pos_str, t_coordinates *position);
static int	parse_color(char *color_str, t_color *color);
static int	add_values(char **line, t_display *display);

int	light(char **line, int *light_count, t_display *display)
{
	if (!line || !light_count || !display)
		return (0);
	if (!line[0] || !line[1] || !line[2] || !line[3])
		return (0);
	if (line[4] != NULL)
		return (0);
	if (!coordinate_check(line[1]))
		return (0);
	if (!ratio_check(line[2]))
		return (0);
	if (!color_check(line[3]))
		return (0);
	(*light_count)++;
	if (*light_count > 1)
		return (0);
	if (!add_values(line, display))
		return (0);
	return (1);
}

static int	parse_position(char *pos_str, t_coordinates *position)
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
