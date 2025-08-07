/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:54:35 by allefran          #+#    #+#             */
/*   Updated: 2025/08/07 10:34:15 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "utils.h"

typedef struct s_sphere
{
	int				diameter;
	t_color			color;
	t_coordinates	position;
}					t_sphere;

typedef struct s_plane
{
	t_color			color;
	t_coordinates	vector;
	t_coordinates	position;
}					t_plane;

typedef struct s_cylinder
{
	int				diameter;
	int				height;
	t_color			color;
	t_coordinates	position;
	t_coordinates	vector;
}					t_cylinder;

#endif