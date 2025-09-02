/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:00:49 by allefran          #+#    #+#             */
/*   Updated: 2025/09/02 14:55:26 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "display.h"
#include "vectors.h"

int	draw_line(t_display *display, t_vector vector, int length, int color)
{
	int	i;
	int	current_x;
	int	current_y;

	t_vector	normed_vector;
	normed_vector = normalize(vector);

	i = 0;
	while (i < length)
	{
		current_x = display->camera.position.x + (normed_vector.x * i) + ORIGIN_X;
		current_y = ORIGIN_Y - display->camera.position.y + (normed_vector.y * i);
		mlx_pixel_put(display->mlx, display->window, current_x, current_y, color);
		i++;
	}
	return (1);
}
