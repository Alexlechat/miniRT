/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:54:35 by allefran          #+#    #+#             */
/*   Updated: 2025/09/30 13:20:28 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "utils.h"

typedef struct s_sphere
{
	double			radius;
	t_color			color;
	t_vector		position;
}					t_sphere;

typedef struct s_plane
{
	t_color			color;
	t_vector		orientation;
	t_vector		position;
}					t_plane;

typedef struct s_cylinder
{
	int				diameter;
	int				height;
	t_color			color;
	t_vector		position;
	t_vector		vector;
}					t_cylinder;

#endif