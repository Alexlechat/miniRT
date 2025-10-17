/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:08:36 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 09:49:14 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "elements.h"
#include "libft.h"
#include "utils.h"
#include "vectors.h"
#include <math.h>
#include <stdio.h>

t_hit			find_closest_hit(t_display *display, t_ray ray);

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

int	create_ray(t_display *display, int pixel_x, int pixel_y)
{
	double			norm_x;
	double			norm_y;
	double			viewport_height;
	double			viewport_width;
	double			ratio;
	t_ray			ray;
	t_hit			hit;
	bool			is_lit;
	double			normalized_angle;
	t_camera_basis	basis;
	t_vector		ray_dir;
	double			ambient_r;
	double			ambient_g;
	double			ambient_b;
	double			diffuse_r;
	double			diffuse_g;
	double			diffuse_b;

	ratio = (double)display->width / (double)display->height;
	norm_x = ((2 * pixel_x / (double)display->width) - 1);
	norm_y = 1 - (2 * pixel_y / (double)display->height);
	viewport_height = 2.0 * tan(((display->camera.fov * M_PI) / 180) / 2.0);
	viewport_width = ratio * viewport_height;
	basis = calculate_camera_basis(display->camera.or);
	hit.hit = false;
	hit.color.color = display->ambient.color.color;
	ray.origin = display->camera.position;
	ray_dir = multiply(basis.right, norm_x * (viewport_width / 2));
	ray_dir = add(ray_dir, multiply(basis.up, norm_y * (viewport_height / 2)));
	ray_dir = add(ray_dir, basis.forward);
	ray.direction = normalize(ray_dir);
	hit = find_closest_hit(display, ray);
	if (hit.hit == true)
	{
		ambient_r = (hit.color.r / 255.0) * (display->ambient.color.r / 255.0)
			* display->ambient.brightness * 255.0 * 0.3;
		ambient_g = (hit.color.g / 255.0) * (display->ambient.color.g / 255.0)
			* display->ambient.brightness * 255.0 * 0.3;
		ambient_b = (hit.color.b / 255.0) * (display->ambient.color.b / 255.0)
			* display->ambient.brightness * 255.0 * 0.3;
		is_lit = reflection(display, hit.coordinate, &hit);
		if (is_lit == true && hit.angle_deg <= 90)
		{
			normalized_angle = 1.0 - (hit.angle_deg / 90);
			diffuse_r = hit.color.r * normalized_angle
				* display->light.brightness;
			diffuse_g = hit.color.g * normalized_angle
				* display->light.brightness;
			diffuse_b = hit.color.b * normalized_angle
				* display->light.brightness;
		}
		else
		{
			diffuse_r = 0;
			diffuse_g = 0;
			diffuse_b = 0;
		}
		if (ambient_r + diffuse_r > 255)
			hit.color.r = 255;
		else
			hit.color.r = (unsigned char)(ambient_r + diffuse_r);
		if (ambient_g + diffuse_g > 255)
			hit.color.g = 255;
		else
			hit.color.g = (unsigned char)(ambient_g + diffuse_g);
		if (ambient_b + diffuse_b > 255)
			hit.color.b = 255;
		else
			hit.color.b = (unsigned char)(ambient_b + diffuse_b);
	}
	mlx_pixel_put(display->mlx, display->window, pixel_x, pixel_y,
		hit.color.color);
	return (0);
}

t_hit	find_closest_hit(t_display *display, t_ray ray)
{
	int		i;
	t_hit	last_hit;
	t_hit	closest_hit;

	i = 0;
	ft_memset(&closest_hit, 0, sizeof(t_hit));
	closest_hit.hit = false;
	while (i < display->nb_spheres)
	{
		last_hit.hit = false;
		sphere_intersection(display, &display->sphere[i], &ray, &last_hit);
		if (last_hit.hit && closest_hit.hit)
		{
			if (last_hit.distance < closest_hit.distance)
				closest_hit = last_hit;
		}
		else if (last_hit.hit)
			closest_hit = last_hit;
		i++;
	}
	i = 0;
	while (i < display->nb_planes)
	{
		last_hit.hit = false;
		plane_intersection(display, &display->plane[i], &ray, &last_hit);
		if (last_hit.hit && closest_hit.hit)
		{
			if (last_hit.distance < closest_hit.distance)
				closest_hit = last_hit;
		}
		else if (last_hit.hit)
			closest_hit = last_hit;
		i++;
	}
	i = 0;
	while (i < display->nb_cylinders)
	{
		last_hit.hit = false;
		cylinder_intersection(display, &display->cylinder[i], &ray, &last_hit);
		if (last_hit.hit && closest_hit.hit)
		{
			if (last_hit.distance < closest_hit.distance)
				closest_hit = last_hit;
		}
		else if (last_hit.hit)
			closest_hit = last_hit;
		i++;
	}
	if (closest_hit.hit == false)
	{
		closest_hit.color.color = 0;
	}
	return (closest_hit);
}
