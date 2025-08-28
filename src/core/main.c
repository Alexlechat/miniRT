/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:26:00 by allefran          #+#    #+#             */
/*   Updated: 2025/08/28 17:12:16 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "display.h"

int	main(int argc, char **argv)
{
	t_display	display;

	display.height = 600;
	display.width = 800;
	if (argc != 2)
		return (print_error("Usage : ./miniRT <scene.rt>\n", 2));
	if (!parse_file(argc, argv[1]))
		return (print_error("Error\n", 2));
	init_window(&display);
	mlx_hook(display.window, EVENT_CLOSE, 0, close_window, &display);
	mlx_key_hook(display.window, key_press, &display);
	mlx_loop(display.mlx);
	return (0);
}
