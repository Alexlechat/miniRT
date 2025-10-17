/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:35:15 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 10:38:10 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	apply_lighting(t_hit *hit, t_lighting lighting)
{
	if (lighting.ambient_r + lighting.diffuse_r > 255)
		hit->color.r = 255;
	else
		hit->color.r = (unsigned char)(lighting.ambient_r + lighting.diffuse_r);
	if (lighting.ambient_g + lighting.diffuse_g > 255)
		hit->color.g = 255;
	else
		hit->color.g = (unsigned char)(lighting.ambient_g + lighting.diffuse_g);
	if (lighting.ambient_b + lighting.diffuse_b > 255)
		hit->color.b = 255;
	else
		hit->color.b = (unsigned char)(lighting.ambient_b + lighting.diffuse_b);
}

t_lighting	calculate_ambient(t_display *display, t_hit hit)
{
	t_lighting	lighting;

	lighting.ambient_r = (hit.color.r / 255.0) * (display->ambient.color.r
			/ 255.0) * display->ambient.brightness * 255.0 * 0.3;
	lighting.ambient_g = (hit.color.g / 255.0) * (display->ambient.color.g
			/ 255.0) * display->ambient.brightness * 255.0 * 0.3;
	lighting.ambient_b = (hit.color.b / 255.0) * (display->ambient.color.b
			/ 255.0) * display->ambient.brightness * 255.0 * 0.3;
	lighting.diffuse_r = 0;
	lighting.diffuse_g = 0;
	lighting.diffuse_b = 0;
	return (lighting);
}

t_lighting	calculate_diffuse(t_display *display, t_hit hit,
		t_lighting lighting)
{
	bool	is_lit;
	double	normalized_angle;

	is_lit = reflection(display, hit.coordinate, &hit);
	if (is_lit == true && hit.angle_deg <= 90)
	{
		normalized_angle = 1.0 - (hit.angle_deg / 90);
		lighting.diffuse_r = hit.color.r * normalized_angle
			* display->light.brightness;
		lighting.diffuse_g = hit.color.g * normalized_angle
			* display->light.brightness;
		lighting.diffuse_b = hit.color.b * normalized_angle
			* display->light.brightness;
	}
	return (lighting);
}
