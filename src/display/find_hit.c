/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:22:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/12 14:22:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"

static void	update_closest(t_hit *closest, t_hit *last)
{
	if (last->hit && closest->hit)
	{
		if (last->distance < closest->distance)
			*closest = *last;
	}
	else if (last->hit)
		*closest = *last;
}

void	check_spheres(t_display *display, t_ray *ray, t_hit *closest)
{
	int		i;
	t_hit	last_hit;

	i = 0;
	while (i < display->nb_spheres)
	{
		last_hit.hit = false;
		sphere_intersection(display, &display->sphere[i], ray, &last_hit);
		update_closest(closest, &last_hit);
		i++;
	}
}

void	check_planes(t_display *display, t_ray *ray, t_hit *closest)
{
	int		i;
	t_hit	last_hit;

	i = 0;
	while (i < display->nb_planes)
	{
		last_hit.hit = false;
		plane_intersection(display, &display->plane[i], ray, &last_hit);
		update_closest(closest, &last_hit);
		i++;
	}
}

void	check_cylinders(t_display *display, t_ray *ray, t_hit *closest)
{
	int		i;
	t_hit	last_hit;

	i = 0;
	while (i < display->nb_cylinders)
	{
		last_hit.hit = false;
		cylinder_intersection(display, &display->cylinder[i], ray, &last_hit);
		update_closest(closest, &last_hit);
		i++;
	}
}
