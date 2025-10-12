/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 08:23:48 by allefran          #+#    #+#             */
/*   Updated: 2025/10/12 14:28:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include "objects.h"

t_vector	sphere_normal(t_sphere *sphere, t_vector *coordinate)
{
	t_vector	normal;

	normal = substract(*coordinate, sphere->position);
	normal = multiply(normal, 1 / sphere->radius);
	return (normal);
}

t_vector	cylinder_normal(t_cylinder *cylinder, t_vector *coordinate)
{
	t_vector	to_hit;
	t_vector	projection;
	t_vector	normal;
	double		proj_length;

	to_hit = substract(*coordinate, cylinder->position);
	proj_length = dot(to_hit, cylinder->orientation);
	projection = multiply(cylinder->orientation, proj_length);
	normal = substract(to_hit, projection);
	normal = normalize(normal);
	return (normal);
}
