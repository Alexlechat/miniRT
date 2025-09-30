/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 08:23:48 by allefran          #+#    #+#             */
/*   Updated: 2025/09/30 08:17:33 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include "objects.h"

t_vector    sphere_normal(t_sphere *sphere, t_vector *coordinate)
{
    t_vector    normal;
    
    normal = substract(*coordinate, sphere->position);
    normal = multiply(normal, 1 / sphere->radius);
    return (normal);
}
