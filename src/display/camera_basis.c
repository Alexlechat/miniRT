/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_basis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:22:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/12 14:22:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "display.h"
#include "vectors.h"
#include "camera_basis.h"

static t_vector	get_world_up(t_vector forward)
{
	t_vector	world_up;

	if (fabs(forward.y) > 0.999)
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
	return (world_up);
}

t_camera_basis	calculate_camera_basis(t_vector orientation)
{
	t_camera_basis	basis;
	t_vector		world_up;

	basis.forward = normalize(orientation);
	world_up = get_world_up(basis.forward);
	basis.right = cross_product(world_up, basis.forward);
	basis.right = normalize(basis.right);
	basis.up = cross_product(basis.forward, basis.right);
	basis.up = normalize(basis.up);
	return (basis);
}

t_vector	calculate_ray_direction(t_camera_basis basis, double norm_x,
				double norm_y, t_display *display)
{
	t_vector	ray_dir;
	double		viewport_height;
	double		viewport_width;
	double		ratio;

	ratio = (double)display->width / (double)display->height;
	viewport_height = 2.0 * tan(((display->camera.fov * M_PI) / 180) / 2.0);
	viewport_width = ratio * viewport_height;
	ray_dir = multiply(basis.right, norm_x * (viewport_width / 2));
	ray_dir = add(ray_dir, multiply(basis.up, norm_y * (viewport_height / 2)));
	ray_dir = add(ray_dir, basis.forward);
	return (normalize(ray_dir));
}
