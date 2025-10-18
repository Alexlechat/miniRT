/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:11:27 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 11:26:51 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

bool	check_cylinder_caps(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
		double t)
{
	t_vector	hit_point;
	t_vector	to_hit;
	double		projection;

	hit_point = add(ray->origin, multiply(ray->direction, t));
	to_hit = substract(hit_point, cylinder->position);
	projection = dot(to_hit, cylinder->or);
	if (projection >= -1e-4 && projection <= cylinder->height + 1e-4)
	{
		fill_cylinder_hit(hit, cylinder, hit_point, t);
		return (true);
	}
	return (false);
}

bool	check_cap_distance(t_vector hit_point, t_vector cap_center,
		t_cylinder *cylinder)
{
	double		dist_sq;
	double		radius_sq;
	t_vector	to_hit;

	to_hit = substract(hit_point, cap_center);
	dist_sq = dot(to_hit, to_hit);
	radius_sq = cylinder->radius * cylinder->radius;
	if (dist_sq <= radius_sq + 1e-4)
		return (true);
	return (false);
}

bool	calculate_cap_hit(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
		double cap_offset)
{
	t_vector	cap_center;
	t_vector	to_cap;
	t_vector	hit_point;
	double		t;
	double		denom;

	cap_center = add(cylinder->position, multiply(cylinder->or, cap_offset));
	denom = dot(ray->direction, cylinder->or);
	if (fabs(denom) < 1e-6)
		return (false);
	to_cap = substract(cap_center, ray->origin);
	t = dot(to_cap, cylinder->or) / denom;
	if (t < 1e-6)
		return (false);
	hit_point = add(ray->origin, multiply(ray->direction, t));
	if (check_cap_distance(hit_point, cap_center, cylinder))
	{
		hit->hit = true;
		hit->coordinate = hit_point;
		hit->distance = t;
		hit->color = cylinder->color;
		set_cap_normal(hit, cylinder, cap_offset);
		return (true);
	}
	return (false);
}

void	set_cap_normal(t_hit *hit, t_cylinder *cylinder, double offset)
{
	if (offset > 0)
		hit->normal = cylinder->or ;
	else
		hit->normal = multiply(cylinder->or, -1);
}

bool	intersect_cap(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
		double cap_offset)
{
	return (calculate_cap_hit(cylinder, ray, hit, cap_offset));
}
