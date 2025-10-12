/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_basis.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:22:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/12 14:22:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BASIS_H
# define CAMERA_BASIS_H

# include "utils.h"
# include "display.h"

typedef struct s_camera_basis
{
	t_vector	right;
	t_vector	up;
	t_vector	forward;
}				t_camera_basis;

t_camera_basis	calculate_camera_basis(t_vector orientation);
t_vector		calculate_ray_direction(t_camera_basis basis, double norm_x,
					double norm_y, t_display *display);

#endif
