/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:50:31 by allefran          #+#    #+#             */
/*   Updated: 2025/10/07 12:09:27 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "display.h"
#include "vectors.h"

double sphere_intersection(t_display *display, t_sphere *sphere, t_ray *ray, t_hit *hit)
{
    double  a;
    double  b;
    double  c;
    t_vector    co;
    double  cod;
    double  radius;
    double  delta;
    double  x1;
    double  x2;

    (void)display;
    radius = sphere->radius;
    a = dot(ray->direction, ray->direction);
    co = substract(ray->origin, sphere->position);
    cod = dot(co, ray->direction);
    b = 2 * cod;
    c = dot(co, co) - (radius * radius);
    delta = (b * b) - 4 * a * c;
    if (delta >= 0)
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        if (x1 >= 0.1)
        {
            hit->hit = true;
            hit->coordinate = multiply(ray->direction, x1);
            hit->distance = x1;
            hit->color = sphere->color;
            hit->normal = sphere_normal(sphere, &hit->coordinate);
            return (x1);
        }
        x2 = (-b + sqrt(delta)) / (2 * a);
        if (x2 >= 0.1)
        {
            hit->hit = true;
            hit->coordinate = multiply(ray->direction, x2);
            hit->distance = x2;
            hit->color = sphere->color;
            hit->normal = sphere_normal(sphere, &hit->coordinate);
            return (x2);
        }
    }
    return (0);
}

double  plane_intersection(t_display *display, t_plane *plane, t_ray *ray, t_hit *hit)
{
    double      t;
    double      denom;
    double      angle_deg;
    double      angle_rad;
    t_vector    light;
    t_vector    op;

    denom = dot(plane->orientation, ray->direction);
    
    op = substract(plane->position, ray->origin);
    
    t = dot(plane->orientation, op) / denom;
    
    light = substract(display->light.position, plane->position);
    light = normalize(light);
    if (t > 0)
    {
        hit->hit = true;
        hit->coordinate = multiply(ray->direction, t);
        hit->distance = t;
        hit->color = plane->color;
        hit->normal = plane->orientation;
        angle_rad = acos(dot(plane->orientation, light));
        angle_deg = angle_rad * 180 / M_PI;
        hit->angle_deg = angle_deg;
        if (angle_deg > 90)
        {
            hit->normal = multiply(plane->orientation, -1);
        }
        return (t);
    }
    return (0);
}

// int cylinder_intersection(t_cylinder *cylinder, t_ray *ray, t_hit *hit)
// {
//     t_vector    u;
//     t_vector    v;
//     double      a;
//     double      b;
//     double      c;

//     u = cross_product(ray->direction, cylinder->orientation);
//     v = substract(cylinder->position, ray->direction);
//     v = cross_product(v, cylinder->orientation);

//     a = dot(u, u);
    
//     return (0);
// }