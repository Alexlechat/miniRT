/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:14:35 by allefran          #+#    #+#             */
/*   Updated: 2025/09/03 15:04:17 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

int	draw_camera(t_display *display);

int	render(t_display *display)
{
	t_vector	vector_1;
	t_vector	vector_2;
	t_vector	vector_3;

	vector_1 = degree_to_vector(90);
	vector_2 = degree_to_vector(0);
	vector_3 = degree_to_vector(70);
	if (!display->window)
		return (1);
	draw_camera(display);
	draw_position(display, display->light.position.x, display->light.position.y,
		GREEN);
	draw_position(display, 100, -10, GREEN);
	draw_line(display, vector_1, 100, BLUE);
	draw_line(display, vector_2, 100, RED);
	draw_line(display, vector_3, 100, GREEN);
	vector_1 = degree_to_vector_mirror(90);
	vector_2 = degree_to_vector_mirror(0);
	vector_3 = degree_to_vector_mirror(70);
	draw_line(display, vector_2, 100, RED);
	draw_line(display, vector_3, 100, GREEN);
	return (0);
}

int	draw_camera(t_display *display)
{
	if (!display->window)
		return (1);
	mlx_pixel_put(display->mlx, display->window, display->camera.position.x
		+ ORIGIN_X, ORIGIN_Y - display->camera.position.y, GREEN);
	return (0);
}

int	draw_position(t_display *display, int x, int y, int color)
{
	if (!display->window)
		return (1);
	mlx_pixel_put(display->mlx, display->window, x + ORIGIN_X, ORIGIN_Y - y,
		color);
	return (0);
}


