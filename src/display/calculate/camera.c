/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:41:31 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 10:50:51 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

t_camera_basis	calculate_camera_basis(t_vector or)
{
	t_camera_basis	basis;
	t_vector		world_up;

	basis.forward = normalize(or);
	if (fabs(basis.forward.y) > 0.999)
	{
		world_up.x = 0;
		world_up.y = 0;
		world_up.z = 1;
	}
	else
	{
		world_up.x = 0;
		world_up.y = 1;
		world_up.z = 0;
	}
	basis.right = cross_product(world_up, basis.forward);
	basis.right = normalize(basis.right);
	basis.up = cross_product(basis.forward, basis.right);
	basis.up = normalize(basis.up);
	return (basis);
}

t_viewport	calculate_viewport(t_display *display, int pixel_x,
		int pixel_y)
{
	t_viewport	viewport;

	viewport.ratio = (double)display->width / (double)display->height;
	viewport.norm_x = ((2 * pixel_x / (double)display->width) - 1);
	viewport.norm_y = 1 - (2 * pixel_y / (double)display->height);
	viewport.height = 2.0 * tan(((display->camera.fov * M_PI) / 180) / 2.0);
	viewport.width = viewport.ratio * viewport.height;
	return (viewport);
}
