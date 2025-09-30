/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:50:31 by allefran          #+#    #+#             */
/*   Updated: 2025/09/30 10:33:03 by allefran         ###   ########.fr       */
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
        x2 = (-b - sqrt(delta)) / (2 * a);
        if (x2 >= 0.001)
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

// int plane_intersection(t_plane plane, t_ray ray, t_hit hit)
// {
//     // a = o2 + t3 * v3                  droite
//     // a = o1 + t1 * v1 + t2 * v2        plan
    
//     // o1 + t1 * v1 + t2 * v2 = o2 + t3 * v3    trouver t3 distance

//     // (o1 + t1 * v1 + t2 * v2  - o2) / v3 = t3
//     // 
    
//     return (0);
// }

// int cylinder_intersection(t_cylinder cylinder, t_ray ray, t_hit hit)
// {
    
//     return (0);
// }