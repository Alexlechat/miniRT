/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:42:16 by allefran          #+#    #+#             */
/*   Updated: 2025/09/02 15:27:17 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "utils.h"

// scalar product
int	dot(t_vector u, t_vector v)
{
	int	scalar;

	scalar = u.x * v.x + u.y * v.y + u.z * v.z;
	return (scalar);
}

t_vector	normalize(t_vector u)
{
	t_vector	result;
	double			norm;

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

t_vector	multiply(t_vector u, int scalar)
{
	t_vector	result;

	result.x = u.x * scalar;
	result.y = u.y * scalar;
	result.z = u.z * scalar;
	return (result);
}
