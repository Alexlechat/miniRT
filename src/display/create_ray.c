/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:08:36 by allefran          #+#    #+#             */
/*   Updated: 2025/09/30 14:42:33 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "utils.h"
#include "display.h"
#include "vectors.h"

t_hit find_closest_hit(t_display *display, t_ray ray);

int create_ray(t_display *display, int pixel_x, int pixel_y)
{
    double  norm_x;
	double	norm_y;
    double  viewport_height;
    double  viewport_width;
    double  ratio;
    t_ray   ray;
    t_hit   hit;
    bool    is_lit;
    double  normalized_angle;

    ratio = (double)display->width / (double)display->height;
    norm_x = ((2 * pixel_x / (double)display->width) - 1);
	norm_y = 1 - (2 * pixel_y / (double)display->height);

    viewport_height = 2.0 * tan(((display->camera.fov * M_PI) / 180) / 2.0);
    viewport_width = ratio * viewport_height;
    
    hit.hit = false;
    hit.color.color = display->ambient.color.color;
    ray.origin = display->camera.position;
    ray.direction.x = norm_x * (viewport_width / 2);
    ray.direction.y = norm_y * (viewport_height / 2);
    ray.direction.z = 1;
    hit = find_closest_hit(display, ray);
    if (hit.hit == true)
    {
        is_lit = reflection(display, hit.coordinate, &hit);
        if (is_lit == true)
        {
            normalized_angle = 1.0 - (hit.angle_deg / 180);
            hit.color.r *= normalized_angle;
            hit.color.g *= normalized_angle;
            hit.color.b *= normalized_angle;
        }
        else
        {
            normalized_angle = 0.2 * (1.0 - (hit.angle_deg / 180.0));
            hit.color.r *= normalized_angle;
            hit.color.g *= normalized_angle;
            hit.color.b *= normalized_angle;
        }
    }   
    mlx_pixel_put(display->mlx, display->window, pixel_x, pixel_y, hit.color.color);
    return (0);
}

t_hit find_closest_hit(t_display *display, t_ray ray)
{
    int     i;
    t_hit   last_hit;
    t_hit   closest_hit;
    
    i = 0;
    closest_hit.hit = false;
    while (i < display->nb_spheres)
    {
        last_hit.hit = false;
        sphere_intersection(display, &display->sphere[i], &ray, &last_hit);
        if (last_hit.hit && closest_hit.hit)
        {
            if (last_hit.distance < closest_hit.distance)
                closest_hit = last_hit;
        }
        else if (last_hit.hit)
            closest_hit = last_hit;
        i++;
    }
    i = 0;
    while (i < display->nb_planes)
    {
        last_hit.hit = false;
        plane_intersection(&display->plane[i], &ray, &last_hit);
        if (last_hit.hit && closest_hit.hit)
        {
            if (last_hit.distance < closest_hit.distance)
                closest_hit = last_hit;
        }
        else if (last_hit.hit)
            closest_hit = last_hit;
        i++;
    }
    i = 0;
    while (i < display->nb_cylinders)
    {
        i++;
    }
    if (closest_hit.hit == false)
    {
        closest_hit.color.color = 0;
    }
    return (closest_hit);
}
