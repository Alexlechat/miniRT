/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:28:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/12 14:28:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "display.h"
#include "vectors.h"

t_vector	cylinder_normal(t_cylinder *cylinder, t_vector *coordinate);

bool	check_cylinder_caps(t_cylinder *cylinder, t_ray *ray,
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
		hit->normal = cylinder_normal(cylinder, &hit_point);
		return (true);
	}
	return (false);
}

static bool	check_cap_distance(t_vector hit_point, t_vector cap_center,
				double radius)
{
	t_vector	to_hit;
	double		dist_sq;

	to_hit = substract(hit_point, cap_center);
	dist_sq = dot(to_hit, to_hit);
	if (dist_sq <= (radius * radius) + 1e-4)
		return (true);
	return (false);
}

static void	set_cap_hit(t_hit *hit, t_vector hit_point, double t,
				t_cylinder *cylinder)
{
	hit->hit = true;
	hit->coordinate = hit_point;
	hit->distance = t;
	hit->color = cylinder->color;
}

static bool	process_cap_hit(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
				double cap_offset)
{
	t_vector	cap_center;
	double		t;
	t_vector	hit_point;

	cap_center = add(cylinder->position, multiply(cylinder->orientation,
				cap_offset));
	t = dot(substract(cap_center, ray->origin), cylinder->orientation)
		/ dot(ray->direction, cylinder->orientation);
	if (t >= 0.001)
	{
		hit_point = add(ray->origin, multiply(ray->direction, t));
		if (check_cap_distance(hit_point, cap_center, cylinder->radius))
		{
			set_cap_hit(hit, hit_point, t, cylinder);
			if (cap_offset > 0)
				hit->normal = cylinder->orientation;
			else
				hit->normal = multiply(cylinder->orientation, -1);
			return (true);
		}
	}
	return (false);
}

bool	intersect_cap(t_cylinder *cylinder, t_ray *ray,
			t_hit *hit, double cap_offset)
{
	double	denom;

	denom = dot(ray->direction, cylinder->orientation);
	if (fabs(denom) > 1e-6)
		return (process_cap_hit(cylinder, ray, hit, cap_offset));
	return (false);
}
