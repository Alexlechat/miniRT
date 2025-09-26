/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:54:35 by allefran          #+#    #+#             */
/*   Updated: 2025/09/26 11:45:26 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "utils.h"

typedef struct s_sphere
{
	double			diameter;
	t_color			color;
	t_vector		position;
}					t_sphere;

typedef struct s_plane
{
	t_color			color;
	t_vector		vector;
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