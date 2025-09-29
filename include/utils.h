/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:38:09 by allefran          #+#    #+#             */
/*   Updated: 2025/09/29 14:17:36 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdbool.h>

typedef union u_color
{
    struct
    {
        unsigned char b;
        unsigned char g;
		unsigned char r;
        unsigned char a;
    };
    int color;
}   t_color;

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}		t_vector;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}		t_ray;

typedef struct s_index
{
	int			index_sphere;
	int			index_plane;
	int			index_cylinder;
}	t_index;

typedef struct s_hit
{
	bool		hit;
	double		distance;
	t_vector	coordinate;
	t_color		color;
	t_vector	normal;
	double		angle_deg;
}			t_hit;

int		convert_color(t_color color);
t_color	create_color(int r, int g, int b);

#endif