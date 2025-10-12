/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:42 by allefran          #+#    #+#             */
/*   Updated: 2025/10/12 14:28:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

bool	solve_quadratic(t_quadratic *quadratic)
{
	quadratic->delta = (quadratic->b * quadratic->b)
		- (4 * quadratic->a * quadratic->c);
	if (quadratic->delta < 0)
		return (false);
	quadratic->solution_1 = (-quadratic->b - sqrt(quadratic->delta))
		/ (quadratic->a * 2);
	quadratic->solution_2 = (-quadratic->b + sqrt(quadratic->delta))
		/ (quadratic->a * 2);
	return (true);
}
