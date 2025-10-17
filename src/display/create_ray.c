/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:08:36 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 09:58:56 by anpicard         ###   ########.fr       */
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
static t_viewport	calculate_viewport(t_display *display, int pixel_x,
					int pixel_y);
static t_ray		calculate_ray(t_display *display, t_viewport viewport);
static t_lighting	calculate_ambient(t_display *display, t_hit hit);
static t_lighting	calculate_diffuse(t_display *display, t_hit hit,
					t_lighting lighting);
static void			apply_lighting(t_hit *hit, t_lighting lighting);
static t_hit		update_closest_hit(t_hit closest_hit, t_hit last_hit);
static t_hit		check_spheres(t_display *display, t_ray ray);
static t_hit		check_planes(t_display *display, t_ray ray,
					t_hit closest_hit);
static t_hit		check_cylinders(t_display *display, t_ray ray,
					t_hit closest_hit);

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

static t_viewport	calculate_viewport(t_display *display, int pixel_x,
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

static t_ray	calculate_ray(t_display *display, t_viewport viewport)
{
	t_camera_basis	basis;
	t_vector		ray_dir;
	t_ray			ray;

	basis = calculate_camera_basis(display->camera.or);
	ray.origin = display->camera.position;
	ray_dir = multiply(basis.right, viewport.norm_x * (viewport.width / 2));
	ray_dir = add(ray_dir, multiply(basis.up, viewport.norm_y
			* (viewport.height / 2)));
	ray_dir = add(ray_dir, basis.forward);
	ray.direction = normalize(ray_dir);
	return (ray);
}

static t_lighting	calculate_ambient(t_display *display, t_hit hit)
{
	t_lighting	lighting;

	lighting.ambient_r = (hit.color.r / 255.0)
		* (display->ambient.color.r / 255.0)
		* display->ambient.brightness * 255.0 * 0.3;
	lighting.ambient_g = (hit.color.g / 255.0)
		* (display->ambient.color.g / 255.0)
		* display->ambient.brightness * 255.0 * 0.3;
	lighting.ambient_b = (hit.color.b / 255.0)
		* (display->ambient.color.b / 255.0)
		* display->ambient.brightness * 255.0 * 0.3;
	lighting.diffuse_r = 0;
	lighting.diffuse_g = 0;
	lighting.diffuse_b = 0;
	return (lighting);
}

static t_lighting	calculate_diffuse(t_display *display, t_hit hit,
		t_lighting lighting)
{
	bool		is_lit;
	double		normalized_angle;

	is_lit = reflection(display, hit.coordinate, &hit);
	if (is_lit == true && hit.angle_deg <= 90)
	{
		normalized_angle = 1.0 - (hit.angle_deg / 90);
		lighting.diffuse_r = hit.color.r * normalized_angle
			* display->light.brightness;
		lighting.diffuse_g = hit.color.g * normalized_angle
			* display->light.brightness;
		lighting.diffuse_b = hit.color.b * normalized_angle
			* display->light.brightness;
	}
	return (lighting);
}

static void	apply_lighting(t_hit *hit, t_lighting lighting)
{
	if (lighting.ambient_r + lighting.diffuse_r > 255)
		hit->color.r = 255;
	else
		hit->color.r = (unsigned char)(lighting.ambient_r
			+ lighting.diffuse_r);
	if (lighting.ambient_g + lighting.diffuse_g > 255)
		hit->color.g = 255;
	else
		hit->color.g = (unsigned char)(lighting.ambient_g
			+ lighting.diffuse_g);
	if (lighting.ambient_b + lighting.diffuse_b > 255)
		hit->color.b = 255;
	else
		hit->color.b = (unsigned char)(lighting.ambient_b
			+ lighting.diffuse_b);
}

int	create_ray(t_display *display, int pixel_x, int pixel_y)
{
	t_viewport		viewport;
	t_ray			ray;
	t_hit			hit;
	t_lighting		lighting;

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

static t_hit	update_closest_hit(t_hit closest_hit, t_hit last_hit)
{
	if (last_hit.hit && closest_hit.hit)
	{
		if (last_hit.distance < closest_hit.distance)
			return (last_hit);
	}
	else if (last_hit.hit)
		return (last_hit);
	return (closest_hit);
}

static t_hit	check_spheres(t_display *display, t_ray ray)
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
		closest_hit = update_closest_hit(closest_hit, last_hit);
		i++;
	}
	return (closest_hit);
}

static t_hit	check_planes(t_display *display, t_ray ray, t_hit closest_hit)
{
	int		i;
	t_hit	last_hit;

	i = 0;
	while (i < display->nb_planes)
	{
		last_hit.hit = false;
		plane_intersection(display, &display->plane[i], &ray, &last_hit);
		closest_hit = update_closest_hit(closest_hit, last_hit);
		i++;
	}
	return (closest_hit);
}

static t_hit	check_cylinders(t_display *display, t_ray ray, t_hit closest_hit)
{
	int		i;
	t_hit	last_hit;

	i = 0;
	while (i < display->nb_cylinders)
	{
		last_hit.hit = false;
		cylinder_intersection(display, &display->cylinder[i], &ray, &last_hit);
		closest_hit = update_closest_hit(closest_hit, last_hit);
		i++;
	}
	return (closest_hit);
}

t_hit	find_closest_hit(t_display *display, t_ray ray)
{
	t_hit	closest_hit;

	closest_hit = check_spheres(display, ray);
	closest_hit = check_planes(display, ray, closest_hit);
	closest_hit = check_cylinders(display, ray, closest_hit);
	if (closest_hit.hit == false)
		closest_hit.color.color = 0;
	return (closest_hit);
}
