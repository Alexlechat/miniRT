/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:26:00 by allefran          #+#    #+#             */
/*   Updated: 2025/09/01 11:06:40 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "display.h"

void init_camera(t_camera *camera);

int	main(int argc, char **argv)
{
	t_display	display;
	t_camera	camera;

	if (argc != 2)
		return (print_error("Usage : ./miniRT <scene.rt>\n", 2));
	init_display(&display);
	if (!parse_file(argv[1], &display))
		return (print_error("Error\n", 2));
	init_camera(&camera);
	init_window(&display);
	mlx_loop_hook(display.mlx, &render, &display);
	mlx_hook(display.window, EVENT_CLOSE, 0, close_window, &display);
	mlx_key_hook(display.window, key_press, &display);
	mlx_loop(display.mlx);
	return (0);
}


