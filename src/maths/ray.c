/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:11:46 by allefran          #+#    #+#             */
/*   Updated: 2025/09/02 15:17:42 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <math.h>

t_vector	degree_to_vector(int angle)
{
	t_vector	vector;
	double		radian;

	angle /= 2;
	radian = angle * M_PI / 180;

	vector.x = -sin(radian);
	vector.y = -cos(radian);
	vector.z = 0;
	return (vector);
}

t_vector	degree_to_vector_mirror(int angle)
{
	t_vector	vector;
	double		radian;

	angle /= 2;
	radian = angle * M_PI / 180;

	vector.x = sin(radian);
	vector.y = -cos(radian);
	vector.z = 0;
	return (vector);
}