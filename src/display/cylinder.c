/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:52:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/12 14:52:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "display.h"
#include "vectors.h"

static void	solve_cylinder_quadratic(t_quadratic *quad, t_cylinder *cylinder,
				t_ray *ray, t_vector *oc)
{
	t_vector	ray_perp;
	t_vector	oc_perp;
	double		axis_dot_ray;
	double		axis_dot_oc;

	axis_dot_ray = dot(cylinder->orientation, ray->direction);
	axis_dot_oc = dot(cylinder->orientation, *oc);
	ray_perp = substract(ray->direction,
			multiply(cylinder->orientation, axis_dot_ray));
	oc_perp = substract(*oc, multiply(cylinder->orientation, axis_dot_oc));
	quad->a = dot(ray_perp, ray_perp);
	quad->b = 2.0 * dot(ray_perp, oc_perp);
	quad->c = dot(oc_perp, oc_perp) - (cylinder->radius * cylinder->radius);
	quad->delta = quad->b * quad->b - 4 * quad->a * quad->c;
}

static bool	check_cylinder_caps(t_cylinder *cylinder, t_ray *ray,
				t_hit *hit, double t)
{
	t_vector	hit_point;
	t_vector	to_hit;
	double		projection;
	double		epsilon;

	epsilon = 1e-4;
	hit_point = add(ray->origin, multiply(ray->direction, t));
	to_hit = substract(hit_point, cylinder->position);
	projection = dot(to_hit, cylinder->orientation);
	if (projection >= -epsilon && projection <= cylinder->height + epsilon)
	{
		hit->hit = true;
		hit->coordinate = hit_point;
		hit->distance = t;
		hit->color = cylinder->color;
		hit->normal = cylinder_normal(cylinder, &hit->coordinate);
		return (true);
	}
	return (false);
}

static bool	intersect_cap(t_cylinder *cylinder, t_ray *ray,
				t_hit *hit, double cap_offset)
{
	t_vector	cap_center;
	double		denom;
	double		t;
	t_vector	to_cap;
	t_vector	hit_point;
	t_vector	to_hit;
	double		dist_sq;

	cap_center = add(cylinder->position,
			multiply(cylinder->orientation, cap_offset));
	denom = dot(ray->direction, cylinder->orientation);
	if (fabs(denom) > 1e-6)
	{
		to_cap = substract(cap_center, ray->origin);
		t = dot(to_cap, cylinder->orientation) / denom;
		if (t >= 0.001)
		{
			hit_point = add(ray->origin, multiply(ray->direction, t));
			to_hit = substract(hit_point, cap_center);
			dist_sq = dot(to_hit, to_hit);
			if (dist_sq <= (cylinder->radius * cylinder->radius) + 1e-4)
			{
				hit->hit = true;
				hit->coordinate = hit_point;
				hit->distance = t;
				hit->color = cylinder->color;
				if (cap_offset > 0)
					hit->normal = cylinder->orientation;
				else
					hit->normal = multiply(cylinder->orientation, -1);
				return (true);
			}
		}
	}
	return (false);
}

double	cylinder_intersection(t_display *display, t_cylinder *cylinder,
			t_ray *ray, t_hit *hit)
{
	t_quadratic	quad;
	t_vector	oc;
	t_hit		cap_hit;

	(void)display;
	oc = substract(ray->origin, cylinder->position);
	solve_cylinder_quadratic(&quad, cylinder, ray, &oc);
	if (quad.delta >= 0)
	{
		quad.solution_1 = (-quad.b - sqrt(quad.delta)) / (2 * quad.a);
		if (quad.solution_1 >= 0.001
			&& check_cylinder_caps(cylinder, ray, hit, quad.solution_1))
			return (quad.solution_1);
		quad.solution_2 = (-quad.b + sqrt(quad.delta)) / (2 * quad.a);
		if (quad.solution_2 >= 0.001
			&& check_cylinder_caps(cylinder, ray, hit, quad.solution_2))
			return (quad.solution_2);
	}
	cap_hit.hit = false;
	if (intersect_cap(cylinder, ray, &cap_hit, 0))
	{
		if (!hit->hit || cap_hit.distance < hit->distance)
		{
			*hit = cap_hit;
			return (cap_hit.distance);
		}
	}
	if (intersect_cap(cylinder, ray, &cap_hit, cylinder->height))
	{
		if (!hit->hit || cap_hit.distance < hit->distance)
		{
			*hit = cap_hit;
			return (cap_hit.distance);
		}
	}
	return (0);
}
