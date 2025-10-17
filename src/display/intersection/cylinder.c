/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:06:32 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 11:24:41 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"

static void		solve_cylinder_quadratic(t_quadratic *quad,
					t_cylinder *cylinder, t_ray *ray, t_vector *oc);
static double	check_body_intersection(t_cylinder *cylinder, t_ray *ray,
					t_hit *hit, t_quadratic *quad);
static void		check_caps_intersection(t_cylinder *cylinder, t_ray *ray,
					t_hit *hit);

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
