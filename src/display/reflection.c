/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:52:40 by allefran          #+#    #+#             */
/*   Updated: 2025/09/30 14:57:39 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

static double l(t_vector v);
t_vector    calculate_light_ray(t_vector origin, t_light *light);

bool    reflection(t_display *display, t_vector origin, t_hit *hit_object)
{
    t_ray   light_ray;
    t_hit   light_hit;
    double  angle;

    angle = 0;
    light_ray.origin = origin;
    light_ray.direction = calculate_light_ray(origin, &display->light);
    light_hit = find_closest_hit(display, light_ray);
    light_hit.normal = hit_object->normal;
    light_hit.normal = normalize(light_hit.normal);
    angle = dot(light_ray.direction, light_hit.normal);
    if (angle < -1)
        angle = -1;
    if (angle > 1)
        angle = 1;
    hit_object->angle_deg = acos(angle) * 180.0 / M_PI;
    return (light_hit.distance > l(substract(display->light.position, origin)));
}

t_vector    calculate_light_ray(t_vector origin, t_light *light)
{
    t_vector    light_ray;

    light_ray = substract(light->position, origin);
    light_ray = normalize(light_ray);
    return (light_ray);
}

static double l(t_vector v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}