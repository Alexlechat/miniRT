/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:32:13 by allefran          #+#    #+#             */
/*   Updated: 2025/08/07 13:00:09 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "utils.h"

typedef struct s_ambient
{
	double			brightness;
	t_color			color;
}					t_ambient;

typedef struct s_camera
{
	int				fov;
	t_coordinates	position;
	t_coordinates	orientation;
}					t_camera;

typedef struct s_light
{
	double			brightness;
	t_color			color;
	t_coordinates	position;
}					t_light;

#endif
