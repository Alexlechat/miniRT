/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:32:13 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 14:18:03 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "utils.h"

typedef struct s_ambient
{
	double		brightness;
	t_color		color;
}				t_ambient;

typedef struct s_camera
{
	int			fov;
	t_vector	position;
	t_vector	or;
}				t_camera;

typedef struct s_camera_basis
{
	t_vector	right;
	t_vector	up;
	t_vector	forward;
}				t_camera_basis;

typedef struct s_light
{
	double		brightness;
	t_color		color;
	t_vector	position;
}				t_light;

#endif
