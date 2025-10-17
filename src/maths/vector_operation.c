/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vactor_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:38:47 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 09:39:32 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
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
