/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:14 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/17 14:23:28 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"
#include "parsing.h"

static int	add_values(char **line, t_display *display);

int	ambient(char **line, int *ambient_count, t_display *display)
{
	if (!line || !ambient_count || !display)
		return (print_error_msg("Invalid ambient light parameters\n"));
	if (!line[0] || !line[1] || !line[2])
		return (print_error_msg("Ambient light: missing parameters\n"));
	if (line[3] != NULL)
		return (print_error_msg("Ambient light: too many parameters\n"));
	if (!ratio_check(line[1]))
		return (print_error_msg("Ambient light: invalid brightness ratio\n"));
	if (!color_check(line[2]))
		return (print_error_msg("Ambient light: invalid color format\n"));
	(*ambient_count)++;
	if (*ambient_count > 1)
		return (print_error_msg("Ambient light: duplicate definition\n"));
	if (!add_values(line, display))
		return (print_error_msg("Ambient light: failed to parse values\n"));
	return (1);
}

static int	add_values(char **line, t_display *display)
{
	char	**color_parts;

	display->ambient.brightness = atof(line[1]);
	color_parts = ft_split(line[2], ',');
	if (!color_parts || !color_parts[0] || !color_parts[1] || !color_parts[2])
	{
		if (color_parts)
			free_str(color_parts);
		return (0);
	}
	display->ambient.color.r = atoi(color_parts[0]);
	display->ambient.color.g = atoi(color_parts[1]);
	display->ambient.color.b = atoi(color_parts[2]);
	free_str(color_parts);
	return (1);
}
