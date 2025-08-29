/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:14 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/29 12:41:55 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../../../libft/includes/libft.h"
#include "display.h"

static int	add_values(char **line, t_display *display);

int	ambient(char **line, int *ambient_count, t_display *display)
{
	if (!line || !ambient_count || !display)
		return (0);
	if (!line[0] || !line[1] || !line[2])
		return (0);
	if (line[3] != NULL)
		return (0);
	if (!ratio_check(line[1]))
		return (0);
	if (!color_check(line[2]))
		return (0);
	(*ambient_count)++;
	if (*ambient_count > 1)
		return (0);
	if (!add_values(line, display))
		return (0);
	return (1);
}

static int	add_values(char **line, t_display *display)
{
	char **color_parts;

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
