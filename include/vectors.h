/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:27:57 by allefran          #+#    #+#             */
/*   Updated: 2025/09/02 15:04:40 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector	t_vector;

int						dot(t_vector u, t_vector v);
t_vector				normalize(t_vector u);
t_vector				add(t_vector u, t_vector v);
t_vector				substract(t_vector u, t_vector v);
t_vector				multiply(t_vector u, int scalar);
t_vector				degree_to_vector(int angle);
t_vector				degree_to_vector_mirror(int angle);

#endif