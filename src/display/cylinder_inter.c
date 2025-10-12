/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
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

bool	check_cylinder_caps(t_cylinder *cylinder, t_ray *ray,
			t_hit *hit, double t);
bool	intersect_cap(t_cylinder *cylinder, t_ray *ray,
			t_hit *hit, double cap_offset);

static void	solve_cylinder_quadratic(t_quadratic *quad, t_cylinder *cylinder,
				t_ray *ray, t_vector *oc)
{
	t_vector	proj_dir;
	t_vector	proj_oc;
	double		dot_dir_axis;
	double		dot_oc_axis;

	dot_dir_axis = dot(ray->direction, cylinder->orientation);
	dot_oc_axis = dot(*oc, cylinder->orientation);
	proj_dir = substract(ray->direction, multiply(cylinder->orientation,
				dot_dir_axis));
	proj_oc = substract(*oc, multiply(cylinder->orientation, dot_oc_axis));
	quad->a = dot(proj_dir, proj_dir);
	quad->b = 2.0 * dot(proj_dir, proj_oc);
	quad->c = dot(proj_oc, proj_oc) - (cylinder->radius * cylinder->radius);
	quad->delta = quad->b * quad->b - 4 * quad->a * quad->c;
}

static double	check_body_intersection(t_quadratic *quad, t_cylinder *cylinder,
					t_ray *ray, t_hit *hit)
{
	if (quad->delta >= 0)
	{
		quad->solution_1 = (-quad->b - sqrt(quad->delta)) / (2 * quad->a);
		if (quad->solution_1 >= 0.001 && check_cylinder_caps(cylinder, ray,
				hit, quad->solution_1))
			return (quad->solution_1);
		quad->solution_2 = (-quad->b + sqrt(quad->delta)) / (2 * quad->a);
		if (quad->solution_2 >= 0.001 && check_cylinder_caps(cylinder, ray,
				hit, quad->solution_2))
			return (quad->solution_2);
	}
	return (0);
}

static double	check_caps_intersection(t_cylinder *cylinder, t_ray *ray,
					t_hit *hit)
{
	t_hit	cap_hit;

	cap_hit.hit = false;
	if (intersect_cap(cylinder, ray, &cap_hit, 0))
	{
		if (!hit->hit || cap_hit.distance < hit->distance)
		{
			*hit = cap_hit;
			return (cap_hit.distance);
		}
	}
	cap_hit.hit = false;
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

double	cylinder_intersection(t_display *display, t_cylinder *cylinder,
			t_ray *ray, t_hit *hit)
{
	t_quadratic	quad;
	t_vector	oc;
	double		result;

	(void)display;
	oc = substract(ray->origin, cylinder->position);
	solve_cylinder_quadratic(&quad, cylinder, ray, &oc);
	result = check_body_intersection(&quad, cylinder, ray, hit);
	if (result > 0)
		return (result);
	return (check_caps_intersection(cylinder, ray, hit));
}
