/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:22:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/12 14:22:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"

static void	calculate_ambient(t_display *display, t_hit *hit, double *amb)
{
	amb[0] = calc_ambient(hit->color.r, display->ambient.color.r,
			display->ambient.brightness);
	amb[1] = calc_ambient(hit->color.g, display->ambient.color.g,
			display->ambient.brightness);
	amb[2] = calc_ambient(hit->color.b, display->ambient.color.b,
			display->ambient.brightness);
}

static void	calculate_diffuse(t_display *display, t_hit *hit, double *diff)
{
	double	normalized_angle;
	bool	is_lit;

	is_lit = reflection(display, hit->coordinate, hit);
	if (is_lit == true && hit->angle_deg <= 90)
	{
		normalized_angle = 1.0 - (hit->angle_deg / 90);
		diff[0] = hit->color.r * normalized_angle * display->light.brightness;
		diff[1] = hit->color.g * normalized_angle * display->light.brightness;
		diff[2] = hit->color.b * normalized_angle * display->light.brightness;
	}
	else
	{
		diff[0] = 0;
		diff[1] = 0;
		diff[2] = 0;
	}
}

void	apply_lighting(t_display *display, t_hit *hit)
{
	double	ambient[3];
	double	diffuse[3];

	calculate_ambient(display, hit, ambient);
	calculate_diffuse(display, hit, diffuse);
	hit->color.r = clamp_color(ambient[0], diffuse[0]);
	hit->color.g = clamp_color(ambient[1], diffuse[1]);
	hit->color.b = clamp_color(ambient[2], diffuse[2]);
}
