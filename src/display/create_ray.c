/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:08:36 by allefran          #+#    #+#             */
/*   Updated: 2025/09/26 12:05:30 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "utils.h"
#include "display.h"

int test_ray(t_display *display, t_ray ray, int pixel_x, int pixel_y);
int cast_ray(t_display *display, t_ray ray, int pixel_x, int pixel_y);

int create_ray(t_display *display, int pixel_x, int pixel_y)
{
    double  norm_x;
	double	norm_y;
    double  viewport_height;
    double  viewport_width;
    double  ratio;
    t_ray   ray;

    ratio = (double)display->width / (double)display->height;
    norm_x = ((2 * pixel_x / (double)display->width) - 1);
	norm_y = 1 - (2 * pixel_y / (double)display->height);

    viewport_height = 2.0 * tan(((display->camera.fov * M_PI) / 180) / 2.0);
    viewport_width = ratio * viewport_height;
    
    ray.origin = display->camera.position;
    ray.direction.x = norm_x * (viewport_width / 2);
    ray.direction.y = norm_y * (viewport_height / 2);
    ray.direction.z = 1;
    cast_ray(display, ray, pixel_x, pixel_y);
    return (0);
}

int cast_ray(t_display *display, t_ray ray, int pixel_x, int pixel_y)
{
    int     i;
    t_hit   last_hit;
    t_hit   closest_hit;
    t_color color;
    
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
        i++;
    }
    i = 0;
    while (i < display->nb_cylinders)
    {
        i++;
    }
    if (closest_hit.hit)
        color = closest_hit.color;
    else
        color = create_color(0, 0, 0);
    mlx_pixel_put(display->mlx, display->window, pixel_x, pixel_y, convert_color(color));
    return (0);
}
