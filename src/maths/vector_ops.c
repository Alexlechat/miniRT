/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:28:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/12 14:28:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
