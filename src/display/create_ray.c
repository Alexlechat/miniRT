/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:08:36 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 14:22:01 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "display.h"
#include "vectors.h"
#include "elements.h"
#include <stdio.h>

static t_ray	calculate_ray(t_display *display, t_viewport viewport);

int	create_ray(t_display *display, int pixel_x, int pixel_y)
{
	t_viewport	viewport;
	t_ray		ray;
	t_hit		hit;
	t_lighting	lighting;

	viewport = calculate_viewport(display, pixel_x, pixel_y);
	ray = calculate_ray(display, viewport);
	hit.hit = false;
	hit.color.color = display->ambient.color.color;
	hit = find_closest_hit(display, ray);
	if (hit.hit == true)
	{
		lighting = calculate_ambient(display, hit);
		lighting = calculate_diffuse(display, hit, lighting);
		apply_lighting(&hit, lighting);
	}
	mlx_pixel_put(display->mlx, display->window, pixel_x, pixel_y,
		hit.color.color);
	return (0);
}

static t_ray	calculate_ray(t_display *display, t_viewport viewport)
{
	t_camera_basis	basis;
	t_vector		ray_dir;
	t_ray			ray;

	basis = calculate_camera_basis(display->camera.or);
	ray.origin = display->camera.position;
	ray_dir = multiply(basis.right, viewport.norm_x * (viewport.width / 2));
	ray_dir = add(ray_dir, multiply(basis.up, viewport.norm_y * (viewport.height
					/ 2)));
	ray_dir = add(ray_dir, basis.forward);
	ray.direction = normalize(ray_dir);
	return (ray);
}
