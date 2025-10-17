/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:52:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/17 09:43:03 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

static t_vector	calculate_ray_perp(t_cylinder *cylinder, t_ray *ray)
{
	t_vector	ray_perp;
	double		axis_dot_ray;

	axis_dot_ray = dot(cylinder->or, ray->direction);
	ray_perp = substract(ray->direction, multiply(cylinder->or, axis_dot_ray));
	return (ray_perp);
}

static t_vector	calculate_oc_perp(t_cylinder *cylinder, t_vector *oc)
{
	t_vector	oc_perp;
	double		axis_dot_oc;

	axis_dot_oc = dot(cylinder->or, *oc);
	oc_perp = substract(*oc, multiply(cylinder->or, axis_dot_oc));
	return (oc_perp);
}

static void	solve_cylinder_quadratic(t_quadratic *quad, t_cylinder *cylinder,
		t_ray *ray, t_vector *oc)
{
	t_vector	ray_perp;
	t_vector	oc_perp;
	double		radius_sq;

	ray_perp = calculate_ray_perp(cylinder, ray);
	oc_perp = calculate_oc_perp(cylinder, oc);
	quad->a = dot(ray_perp, ray_perp);
	quad->b = 2.0 * dot(ray_perp, oc_perp);
	radius_sq = cylinder->radius * cylinder->radius;
	quad->c = dot(oc_perp, oc_perp) - radius_sq;
	solve_quadratic(quad);
}

static void	fill_cylinder_hit(t_hit *hit, t_cylinder *cylinder, t_vector point,
		double t)
{
	hit->hit = true;
	hit->coordinate = point;
	hit->distance = t;
	hit->color = cylinder->color;
	hit->normal = cylinder_normal(cylinder, &hit->coordinate);
}

static bool	check_cylinder_caps(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
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

static void	set_cap_normal(t_hit *hit, t_cylinder *cylinder, double offset)
{
	if (offset > 0)
		hit->normal = cylinder->or;
	else
		hit->normal = multiply(cylinder->or, -1);
}

static bool	check_cap_distance(t_vector hit_point, t_vector cap_center,
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

static bool	calculate_cap_hit(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
		double cap_offset)
{
	t_vector	cap_center;
	t_vector	to_cap;
	t_vector	hit_point;
	double		t;
	double		denom;

	cap_center = add(cylinder->position, multiply(cylinder->or, cap_offset));
	denom = dot(ray->direction, cylinder->or);
	if (fabs(denom) <= 1e-6)
		return (false);
	to_cap = substract(cap_center, ray->origin);
	t = dot(to_cap, cylinder->or) / denom;
	if (t < 0.001)
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

static bool	intersect_cap(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
		double cap_offset)
{
	return (calculate_cap_hit(cylinder, ray, hit, cap_offset));
}

static double	check_body_intersection(t_cylinder *cylinder, t_ray *ray,
		t_hit *hit, t_quadratic *quad)
{
	if (quad->delta < 0)
		return (0);
	if (quad->solution_1 >= 0.001)
	{
		if (check_cylinder_caps(cylinder, ray, hit, quad->solution_1))
			return (quad->solution_1);
	}
	if (quad->solution_2 >= 0.001)
	{
		if (check_cylinder_caps(cylinder, ray, hit, quad->solution_2))
			return (quad->solution_2);
	}
	return (0);
}

static void	update_hit_if_closer(t_hit *hit, t_hit *cap_hit)
{
	if (cap_hit->hit)
	{
		if (!hit->hit || cap_hit->distance < hit->distance)
			*hit = *cap_hit;
	}
}

static void	check_caps_intersection(t_cylinder *cylinder, t_ray *ray,
		t_hit *hit)
{
	t_hit	cap_hit;

	cap_hit.hit = false;
	intersect_cap(cylinder, ray, &cap_hit, 0);
	update_hit_if_closer(hit, &cap_hit);
	cap_hit.hit = false;
	intersect_cap(cylinder, ray, &cap_hit, cylinder->height);
	update_hit_if_closer(hit, &cap_hit);
}

double	cylinder_intersection(t_display *display, t_cylinder *cylinder,
		t_ray *ray, t_hit *hit)
{
	t_quadratic	quad;
	t_vector	oc;
	double		result;

	(void)display;
	oc = substract(ray->origin, cylinder->position);
	solve_cylinder_quadratic(&quad, cylinder, ray, &oc);
	result = check_body_intersection(cylinder, ray, hit, &quad);
	if (result > 0)
		return (result);
	check_caps_intersection(cylinder, ray, hit);
	if (hit->hit)
		return (hit->distance);
	return (0);
}
