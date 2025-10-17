/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:44:16 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 14:21:44 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"

static t_hit	check_spheres(t_display *display, t_ray ray);
static t_hit	check_planes(t_display *display, t_ray ray, t_hit closest_hit);
static t_hit	check_cylinders(t_display *display, t_ray ray,
					t_hit closest_hit);

t_hit	find_closest_hit(t_display *display, t_ray ray)
{
	t_hit	closest_hit;

	closest_hit = check_spheres(display, ray);
	closest_hit = check_planes(display, ray, closest_hit);
	closest_hit = check_cylinders(display, ray, closest_hit);
	if (closest_hit.hit == false)
		closest_hit.color.color = 0;
	return (closest_hit);
}

t_hit	update_closest_hit(t_hit closest_hit, t_hit last_hit)
{
	if (last_hit.hit && closest_hit.hit)
	{
		if (last_hit.distance < closest_hit.distance)
			return (last_hit);
	}
	else if (last_hit.hit)
		return (last_hit);
	return (closest_hit);
}

static t_hit	check_spheres(t_display *display, t_ray ray)
{
	int		i;
	t_hit	last_hit;
	t_hit	closest_hit;

	i = 0;
	ft_memset(&closest_hit, 0, sizeof(t_hit));
	closest_hit.hit = false;
	while (i < display->nb_spheres)
	{
		last_hit.hit = false;
		sphere_intersection(display, &display->sphere[i], &ray, &last_hit);
		closest_hit = update_closest_hit(closest_hit, last_hit);
		i++;
	}
	return (closest_hit);
}

static t_hit	check_planes(t_display *display, t_ray ray, t_hit closest_hit)
{
	int		i;
	t_hit	last_hit;

	i = 0;
	while (i < display->nb_planes)
	{
		last_hit.hit = false;
		plane_intersection(display, &display->plane[i], &ray, &last_hit);
		closest_hit = update_closest_hit(closest_hit, last_hit);
		i++;
	}
	return (closest_hit);
}

static t_hit	check_cylinders(t_display *display, t_ray ray,
		t_hit closest_hit)
{
	int		i;
	t_hit	last_hit;

	i = 0;
	while (i < display->nb_cylinders)
	{
		last_hit.hit = false;
		cylinder_intersection(display, &display->cylinder[i], &ray, &last_hit);
		closest_hit = update_closest_hit(closest_hit, last_hit);
		i++;
	}
	return (closest_hit);
}
