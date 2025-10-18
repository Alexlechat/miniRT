/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:39:10 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/17 14:11:54 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
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
		return (print_error_msg("Plane: invalid position coordinates\n"));
	if (line[2] && !vector_orientation_check(line[2]))
		return (print_error_msg("Plane: invalid orientation vector\n"));
	if (line[3] && !color_check(line[3]))
		return (print_error_msg("Plane: invalid color format\n"));
	if (line[4])
		return (print_error_msg("Plane: too many parameters\n"));
	if (!add_values_pl(line, display))
		return (print_error_msg("Plane: failed to parse values\n"));
	return (1);
}

static int	sphere(char **line, t_display *display)
{
	double	diameter;

	if (line[1] && !coordinate_check(line[1]))
		return (print_error_msg("Sphere: invalid position coordinates\n"));
	if (line[2])
	{
		if (!is_valid_number(line[2]))
			return (print_error_msg("Sphere: invalid diameter format\n"));
		diameter = ft_atof(line[2]);
		if (diameter <= 0)
			return (print_error_msg("Sphere: diameter must be positive\n"));
	}
	if (line[3] && !color_check(line[3]))
		return (print_error_msg("Sphere: invalid color format\n"));
	if (line[4])
		return (print_error_msg("Sphere: too many parameters\n"));
	if (!add_values_sp(line, display))
		return (print_error_msg("Sphere: failed to parse values\n"));
	return (1);
}

static int	validate_cylinder_dimensions(char **line)
{
	double	diameter;
	double	height;

	if (line[3])
	{
		if (!is_valid_number(line[3]))
			return (print_error_msg("Cylinder: invalid diameter format\n"));
		diameter = ft_atof(line[3]);
		if (diameter <= 0)
			return (print_error_msg("Cylinder: diameter must be positive\n"));
	}
	if (line[4])
	{
		if (!is_valid_number(line[4]))
			return (print_error_msg("Cylinder: invalid height format\n"));
		height = ft_atof(line[4]);
		if (height <= 0)
			return (print_error_msg("Cylinder: height must be positive\n"));
	}
	return (1);
}

static int	cylinder(char **line, t_display *display)
{
	if (line[1] && !coordinate_check(line[1]))
		return (print_error_msg("Cylinder: invalid position coordinates\n"));
	if (line[2] && !vector_orientation_check(line[2]))
		return (print_error_msg("Cylinder: invalid orientation vector\n"));
	if (!validate_cylinder_dimensions(line))
		return (0);
	if (line[5] && !color_check(line[5]))
		return (print_error_msg("Cylinder: invalid color format\n"));
	if (line[6])
		return (print_error_msg("Cylinder: too many parameters\n"));
	if (!add_values_cy(line, display))
		return (print_error_msg("Cylinder: failed to parse values\n"));
	return (1);
}
