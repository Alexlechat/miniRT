/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:38:09 by allefran          #+#    #+#             */
/*   Updated: 2025/09/26 11:45:57 by allefran         ###   ########.fr       */
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
	double		distance;
	t_vector	coordinate;
	t_color		color;
}			t_hit;

int		convert_color(t_color color);
t_color	create_color(int r, int g, int b);

#endif