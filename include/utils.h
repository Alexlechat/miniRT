/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:38:09 by allefran          #+#    #+#             */
/*   Updated: 2025/09/03 14:08:30 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
}			t_coordinates;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

#endif