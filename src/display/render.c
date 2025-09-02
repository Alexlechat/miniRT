/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:14:35 by allefran          #+#    #+#             */
/*   Updated: 2025/09/02 09:16:02 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		draw_origin(t_display *display);
int		draw_camera(t_display *display);

int	render(t_display *display)
{
	if (!display->window)
		return (1);
	draw_origin(display);
	draw_camera(display);
	return (0);
}

int	draw_camera(t_display *display)
{
	if (!display->window)
		return (1);
	mlx_pixel_put(display->mlx, display->window, display->camera.position.x + ORIGIN_X,
		ORIGIN_Y - display->camera.position.y, GREEN);
	return (0);
}

int	draw_origin(t_display *display)
{
	if (!display->window)
		return (1);
	mlx_pixel_put(display->mlx, display->window, ORIGIN_X, ORIGIN_Y, RED);
	return (0);
}

