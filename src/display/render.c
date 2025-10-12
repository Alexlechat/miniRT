/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:14:35 by allefran          #+#    #+#             */
/*   Updated: 2025/10/02 14:19:48 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

int	draw_camera(t_display *display);

int	render_scene(t_display *display)
{
	int			pixel_x;
	int			pixel_y;

	pixel_y = 0;
	while (pixel_y < display->height)
	{
		pixel_x = 0;
		while (pixel_x < display->width)
		{
			create_ray(display, pixel_x, pixel_y);
			pixel_x++;
		}
		pixel_y++;
	}
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
