/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:27:57 by allefran          #+#    #+#             */
/*   Updated: 2025/09/25 15:33:36 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_vector	t_vector;

double	                dot(t_vector u, t_vector v);
t_vector				normalize(t_vector u);
t_vector				add(t_vector u, t_vector v);
t_vector				substract(t_vector u, t_vector v);
t_vector				multiply(t_vector u, int scalar);
t_vector				degree_to_vector(int angle);
t_vector				degree_to_vector_mirror(int angle);

double					convert_degree(double degree);
void					calculate_focal(t_display *display);
void					camera_offset(t_display *display);
void					position_offset(t_display *display);

#endif