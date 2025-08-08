/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:39:10 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 15:11:49 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

static int	sphere(char **line);
static int	plane(char **line);
static int	cylinder(char **line);

int	bonus_check(char **line_splited)
{
	if (ft_strncmp(line_splited[0], "pl", 2))
		return (plane(line_splited));
	else if (ft_strncmp(line_splited[0], "sp", 2))
		return (sphere(line_splited));
	else if (ft_strncmp(line_splited[0], "cy", 2))
		return (cylinder(line_splited));
	return (0);
}

static int	plane(char **line)
{
	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2] && !vector_orientation_check(line[2]))
		return (0);
	if (line[3] && !color_check(line[3]))
		return (0);
	if (line[4])
		return (0);
	return (1);
}

static int	sphere(char **line)
{
	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2] && !ft_atof(line[2]))
		return (0);
	if (line[3] && !color_check(line[3]))
		return (0);
	if (line[4])
		return (0);
	return (1);
}

static int	cylinder(char **line)
{
	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2] && !vector_orientation_check(line[2]))
		return (0);
	if (line[3] && !ft_atof(line[3]))
		return (0);
	if (line[4] && !ft_atof(line[4]))
		return (0);
	if (line[5] && !color_check(line[5]))
		return (0);
	if (line[6])
		return (0);
	return (1);
}
