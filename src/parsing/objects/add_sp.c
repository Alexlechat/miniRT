/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:55:43 by anpicard          #+#    #+#             */
/*   Updated: 2025/09/29 12:45:18 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "miniRT.h"

static int	parse_position(char *pos_str, t_vector *position);
static int	parse_color(char *color_str, t_color *color);

int	add_values_sp(char **line, t_display *display)
{
	t_sphere	*new_spheres;
	int			current_index;

	new_spheres = malloc(sizeof(t_sphere) * (display->nb_spheres + 1));
	if (!new_spheres)
		return (0);
	if (display->sphere && display->nb_spheres > 0)
	{
		ft_memcpy(new_spheres, display->sphere, sizeof(t_sphere)
			* display->nb_spheres);
		free(display->sphere);
	}
	display->sphere = new_spheres;
	current_index = display->nb_spheres;
	if (!parse_position(line[1], &display->sphere[current_index].position))
		return (0);
	display->sphere[current_index].radius = ft_atoi(line[2]) / 2;
	if (!parse_color(line[3], &display->sphere[current_index].color))
		return (0);
	display->nb_spheres++;
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
