/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:27:57 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 13:35:42 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_vector	t_vector;

// -----------------------MATHS---------------------
void					calculate_focal(t_display *display);
void					camera_offset(t_display *display);
void					position_offset(t_display *display);
t_vector				add(t_vector u, t_vector v);
t_vector				substract(t_vector u, t_vector v);
t_vector				multiply(t_vector u, double scalar);
double					dot(t_vector u, t_vector v);
t_vector				cross_product(t_vector u, t_vector v);
t_vector				normalize(t_vector u);

#endif