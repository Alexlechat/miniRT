/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:50:31 by allefran          #+#    #+#             */
/*   Updated: 2025/10/12 14:28:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "display.h"
#include "vectors.h"

static double	check_sphere_hit(t_ray *ray, t_sphere *sphere,
					t_hit *hit, double x)
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

double	sphere_intersection(t_display *display, t_sphere *sphere,
			t_ray *ray, t_hit *hit)
{
	double		a;
	double		b;
	double		c;
	t_vector	co;
	double		delta;
	double		result;

	(void)display;
	a = dot(ray->direction, ray->direction);
	co = substract(ray->origin, sphere->position);
	b = 2 * dot(co, ray->direction);
	c = dot(co, co) - (sphere->radius * sphere->radius);
	delta = (b * b) - 4 * a * c;
	if (delta >= 0)
	{
		result = check_sphere_hit(ray, sphere, hit,
				(-b - sqrt(delta)) / (2 * a));
		if (result > 0)
			return (result);
		return (check_sphere_hit(ray, sphere, hit,
				(-b + sqrt(delta)) / (2 * a)));
	}
	return (0);
}

double	plane_intersection(t_display *display, t_plane *plane,
			t_ray *ray, t_hit *hit)
{
	double		t;
	double		denom;
	double		angle_deg;
	t_vector	light;
	t_vector	op;

	denom = dot(plane->orientation, ray->direction);
	op = substract(plane->position, ray->origin);
	t = dot(plane->orientation, op) / denom;
	light = substract(display->light.position, plane->position);
	light = normalize(light);
	if (t >= 0.001)
	{
		hit->hit = true;
		hit->coordinate = add(ray->origin, multiply(ray->direction, t));
		hit->distance = t;
		hit->color = plane->color;
		hit->normal = plane->orientation;
		angle_deg = acos(dot(plane->orientation, light)) * 180 / M_PI;
		hit->angle_deg = angle_deg;
		if (angle_deg > 90)
			hit->normal = multiply(plane->orientation, -1);
		return (t);
	}
	return (0);
}
