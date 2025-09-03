/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 09:33:28 by allefran          #+#    #+#             */
/*   Updated: 2025/09/03 14:07:33 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <math.h>

static void	reset_camera(t_display *display);

double	convert_degree(double degree)
{
	return (degree * M_PI / 180);
}

void	calculate_focal(t_display *display)
{
	display->focal_length = (display->width / 2) / tan(display->camera.fov / 2);
}

void	camera_offset(t_display *display)
{
	display->vector_offset.x = display->camera.position.x * (-1);
	display->vector_offset.y = display->camera.position.y * (-1);
	display->vector_offset.z = display->camera.position.z * (-1);
	reset_camera(display);
}

static void	reset_camera(t_display *display)
{
	display->camera.position.x = 0;
	display->camera.position.y = 0;
	display->camera.position.z = 0;
}
