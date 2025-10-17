/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:50:31 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 09:43:14 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

static void	solve_sphere_quadratic(t_quadratic *quad, t_sphere *sphere,
		t_ray *ray)
{
	t_vector	co;

	co = substract(ray->origin, sphere->position);
	quad->a = dot(ray->direction, ray->direction);
	quad->b = 2 * dot(co, ray->direction);
	quad->c = dot(co, co) - (sphere->radius * sphere->radius);
	solve_quadratic(quad);
}

static double	check_sphere_hit(t_ray *ray, t_sphere *sphere, t_hit *hit,
		double x)
{
	if (x >= 0.001)
	{
		hit->hit = true;
		hit->coordinate = add(ray->origin, multiply(ray->direction, x));
		hit->distance = x;
		hit->color = sphere->color;
		hit->normal = sphere_normal(sphere, &hit->coordinate);
		return (x);
	}
	return (0);
}

double	sphere_intersection(t_display *display, t_sphere *sphere, t_ray *ray,
		t_hit *hit)
{
	t_quadratic	quad;
	double		result;

	(void)display;
	solve_sphere_quadratic(&quad, sphere, ray);
	if (quad.delta < 0)
		return (0);
	result = check_sphere_hit(ray, sphere, hit, quad.solution_1);
	if (result > 0)
		return (result);
	return (check_sphere_hit(ray, sphere, hit, quad.solution_2));
}

double	plane_intersection(t_display *display, t_plane *plane, t_ray *ray,
		t_hit *hit)
{
	double		t;
	double		denom;
	double		angle_deg;
	t_vector	light;
	t_vector	op;

	denom = dot(plane->or, ray->direction);
	op = substract(plane->position, ray->origin);
	t = dot(plane->or, op) / denom;
	light = substract(display->light.position, plane->position);
	light = normalize(light);
	if (t >= 0.001)
	{
		hit->hit = true;
		hit->coordinate = add(ray->origin, multiply(ray->direction, t));
		hit->distance = t;
		hit->color = plane->color;
		hit->normal = plane->or ;
		angle_deg = acos(dot(plane->or, light)) * 180 / M_PI;
		hit->angle_deg = angle_deg;
		if (angle_deg > 90)
			hit->normal = multiply(plane->or, -1);
		return (t);
	}
	return (0);
}
