/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:14:35 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 09:43:26 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"
#include <math.h>

int	render_scene(t_display *display)
{
	int	pixel_x;
	int	pixel_y;

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
