/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:42:16 by allefran          #+#    #+#             */
/*   Updated: 2025/10/12 14:28:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "utils.h"

double	dot(t_vector u, t_vector v)
{
	double	scalar;

	scalar = u.x * v.x + u.y * v.y + u.z * v.z;
	return (scalar);
}

t_vector	cross_product(t_vector u, t_vector v)
{
	t_vector	result;

	result.x = (u.y * v.z) - (u.z * v.y);
	result.y = (u.z * v.x) - (u.x * v.z);
	result.z = (u.x * v.y) - (u.y * v.x);
	return (result);
}

t_vector	normalize(t_vector u)
{
	t_vector	result;
	double		norm;

	norm = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
	if (norm > 0)
	{
		result.x = u.x / norm;
		result.y = u.y / norm;
		result.z = u.z / norm;
	}
	else
	{
		result.x = 0;
		result.y = 0;
		result.z = 0;
	}
	return (result);
}

t_vector	add(t_vector u, t_vector v)
{
	t_vector	result;

	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return (result);
}

t_vector	substract(t_vector u, t_vector v)
{
	t_vector	result;

	result.x = u.x - v.x;
	result.y = u.y - v.y;
	result.z = u.z - v.z;
	return (result);
}

t_vector	multiply(t_vector u, double scalar)
{
	t_vector	result;

	result.x = u.x * scalar;
	result.y = u.y * scalar;
	result.z = u.z * scalar;
	return (result);
}
