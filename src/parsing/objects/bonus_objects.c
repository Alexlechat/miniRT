/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:39:10 by anpicard          #+#    #+#             */
/*   Updated: 2025/09/03 13:51:21 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "display.h"

static int	sphere(char **line, t_display *display);
static int	plane(char **line, t_display *display);
static int	cylinder(char **line, t_display *display);

int	bonus_check(char **line_splited, t_display *display)
{
	if (ft_strncmp(line_splited[0], "pl", 2) == 0)
		return (plane(line_splited, display));
	else if (ft_strncmp(line_splited[0], "sp", 2) == 0)
		return (sphere(line_splited, display));
	else if (ft_strncmp(line_splited[0], "cy", 2) == 0)
		return (cylinder(line_splited, display));
	return (0);
}

static int	plane(char **line, t_display *display)
{
	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2] && !vector_orientation_check(line[2]))
		return (0);
	if (line[3] && !color_check(line[3]))
		return (0);
	if (line[4])
		return (0);
	if (!add_values_pl(line, display))
		return (0);
	return (1);
}

static int	sphere(char **line, t_display *display)
{
	double	diameter;

	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2])
	{
		if (!is_valid_number(line[2]))
			return (0);
		diameter = ft_atof(line[2]);
		if (diameter <= 0)
			return (0);
	}
	if (line[3] && !color_check(line[3]))
		return (0);
	if (line[4])
		return (0);
	if (!add_values_sp(line, display))
		return (0);
	return (1);
}

static int	validate_cylinder_dimensions(char **line)
{
	double	diameter;
	double	height;

	if (line[3])
	{
		if (!is_valid_number(line[3]))
			return (0);
		diameter = ft_atof(line[3]);
		if (diameter <= 0)
			return (0);
	}
	if (line[4])
	{
		if (!is_valid_number(line[4]))
			return (0);
		height = ft_atof(line[4]);
		if (height <= 0)
			return (0);
	}
	return (1);
}

static int	cylinder(char **line, t_display *display)
{
	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2] && !vector_orientation_check(line[2]))
		return (0);
	if (!validate_cylinder_dimensions(line))
		return (0);
	if (line[5] && !color_check(line[5]))
		return (0);
	if (line[6])
		return (0);
	if (!add_values_cy(line, display))
		return (0);
	return (1);
}
