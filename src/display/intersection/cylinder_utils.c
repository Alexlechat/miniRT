/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:52:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/17 11:22:49 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

t_vector	calculate_ray_perp(t_cylinder *cylinder, t_ray *ray)
{
	t_vector	ray_perp;
	double		axis_dot_ray;

	axis_dot_ray = dot(cylinder->or, ray->direction);
	ray_perp = substract(ray->direction, multiply(cylinder->or, axis_dot_ray));
	return (ray_perp);
}

t_vector	calculate_oc_perp(t_cylinder *cylinder, t_vector *oc)
{
	t_vector	oc_perp;
	double		axis_dot_oc;

	axis_dot_oc = dot(cylinder->or, *oc);
	oc_perp = substract(*oc, multiply(cylinder->or, axis_dot_oc));
	return (oc_perp);
}

void	fill_cylinder_hit(t_hit *hit, t_cylinder *cylinder, t_vector point,
		double t)
{
	hit->hit = true;
	hit->coordinate = point;
	hit->distance = t;
	hit->color = cylinder->color;
	hit->normal = cylinder_normal(cylinder, &hit->coordinate);
}

void	update_hit_if_closer(t_hit *hit, t_hit *cap_hit)
{
	if (cap_hit->hit)
	{
		if (!hit->hit || cap_hit->distance < hit->distance)
			*hit = *cap_hit;
	}
}
