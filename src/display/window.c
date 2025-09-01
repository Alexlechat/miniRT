/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:41:50 by allefran          #+#    #+#             */
/*   Updated: 2025/09/01 09:06:29 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "display.h"

int	close_window(t_display *display);

static void	init_mlx(t_display *display)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		close_window(display);
}

void	init_window(t_display *display)
{
	init_mlx(display);
	display->window = mlx_new_window(display->mlx, display->width,
			display->height, "miniRT");
	if (!display->window)
		close_window(display);
}

int	close_window(t_display *display)
{
	if (display->window)
		mlx_destroy_window(display->mlx, display->window);
	if (display->mlx)
	{
		mlx_destroy_display(display->mlx);
		free(display->mlx);
	}
	exit (0);
}

int	key_press(int key_code, t_display *display)
{
	if (key_code == KEY_ESC)
		close_window(display);
	return (0);
}

