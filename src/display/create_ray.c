/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:08:36 by allefran          #+#    #+#             */
/*   Updated: 2025/09/23 14:57:11 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "display.h"
#include "utils.h"

int cast_ray(t_display *display, t_ray ray);

int create_ray(t_display *display, int pixel_x, int pixel_y)
{
    double  norm_x;
	double	norm_y;
    double  viewport_height;
    double  viewport_width;
    double  ratio;
    t_ray   ray;

    ratio = display->width / display->height;
    norm_x = ((2 * pixel_x / display->width) - 1) * ratio;
	norm_y = 1 - (2 * pixel_y / display->height);

    viewport_height = 2.0 * tan(display->camera.fov / 2.0);
    viewport_width = ratio * viewport_height;
    
    ray.origin = display->camera.position;
    ray.direction.x = norm_x * (viewport_width / 2);
    ray.direction.y = norm_y * (viewport_height / 2);
    ray.direction.z = -1;
    cast_ray(display, ray);
    return (0);
}

int cast_ray(t_display *display, t_ray ray)
{
    int     i;
    t_hit   hit;

    i = 0;
    while (i < display->nb_cylinders)
    {
        sphere_intersection(display->sphere[i], ray, hit);
        i++;
    }
    i = 0;
    while (i < display->nb_planes)
    {
        i++;
    }
    i = 0;
    while (i < display->nb_cylinders)
    {
        i++;
    }
    return (0);
}
