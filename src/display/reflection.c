/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:52:40 by allefran          #+#    #+#             */
/*   Updated: 2025/09/29 14:58:19 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

t_vector    calculate_light_ray(t_vector origin, t_light *light);

bool    reflection(t_display *display, t_vector origin)
{
    t_ray   light_ray;
    t_hit   hit;
    double  angle;

    light_ray.origin = origin;
    light_ray.direction = calculate_light_ray(origin, &display->light);
    hit = find_closest_hit(display, light_ray);
    if (hit.hit == false)
    {
        hit.normal = normalize(hit.normal);
        angle = dot(light_ray.direction, hit.normal);
        if (angle < -1)
            angle = -1;
        if (angle > 1)
            angle = 1;
        hit.angle_deg = acos(angle) * 180.0 / M_PI;;
        return (true);
    }
    else
        return (false);
}

t_vector    calculate_light_ray(t_vector origin, t_light *light)
{
    t_vector    light_ray;

    light_ray = substract(light->position, origin);
    light_ray = normalize(light_ray);
    return (light_ray);
}

