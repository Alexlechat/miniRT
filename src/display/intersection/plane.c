/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:54:47 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 11:37:37 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

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
