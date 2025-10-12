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

static void	calc_sphere_params(t_ray *ray, t_sphere *sphere, double *params)
{
	t_vector	co;

	params[0] = dot(ray->direction, ray->direction);
	co = substract(ray->origin, sphere->position);
	params[1] = 2 * dot(co, ray->direction);
	params[2] = dot(co, co) - (sphere->radius * sphere->radius);
	params[3] = (params[1] * params[1]) - 4 * params[0] * params[2];
}

double	sphere_intersection(t_display *display, t_sphere *sphere,
			t_ray *ray, t_hit *hit)
{
	double		params[4];
	double		result;

	(void)display;
	calc_sphere_params(ray, sphere, params);
	if (params[3] >= 0)
	{
		result = check_sphere_hit(ray, sphere, hit,
				(-params[1] - sqrt(params[3])) / (2 * params[0]));
		if (result > 0)
			return (result);
		return (check_sphere_hit(ray, sphere, hit,
				(-params[1] + sqrt(params[3])) / (2 * params[0])));
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
