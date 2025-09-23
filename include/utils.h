/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:38:09 by allefran          #+#    #+#             */
/*   Updated: 2025/09/23 14:45:22 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdbool.h>

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}			t_ray;

typedef struct s_hit
{
	bool		hit;
	t_vector	coordinate;
	int			distance;
	int			color;
}			t_hit;

#endif