/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:50:31 by allefran          #+#    #+#             */
/*   Updated: 2025/10/02 15:01:34 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "display.h"
#include "vectors.h"

double sphere_intersection(t_display *display, t_sphere *sphere, t_ray *ray, t_hit *hit)
{
    // a = o1 + t1 * v1                         droite
    // r = || a - o2||                          sphere
    // r * r = || a - o2|| * || a - o2||

    // o1 + t1 * v1 = (a - o2).(a - o2)

    // a = o1 + t1 * v1
    // r * r = (a - o2).(a - o2)

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
    // a = o2 + t3 * v3                  droite
    // a = o1 + t1 * v1 + t2 * v2        plan
    
    // o1 + t1 * v1 + t2 * v2 = o2 + t3 * v3    trouver t3 distance

    // (o1 + t1 * v1 + t2 * v2  - o2) / v3 = t3
    

    // n . (P - P0) = 0                 plan
    // P(t) = 0rigin + t . direction     droite

    // n . (O + t.d - P0) = 0 

    // t = n · (P₀ - O) / (n · d)

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

// int cylinder_intersection(t_cylinder cylinder, t_ray ray, t_hit hit)
// {
    
//     return (0);
// }