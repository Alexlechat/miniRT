/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:26:00 by allefran          #+#    #+#             */
/*   Updated: 2025/09/03 14:06:55 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_display	display;

	if (argc != 2)
		return (print_error("Usage : ./miniRT <scene.rt>\n", 2));
	ft_memset(&display, 0, sizeof(display));
	init_display(&display);
	if (!parse_file(argv[1], &display))
		return (print_error("Error\n", 2));
	init_window(&display);
	mlx_loop_hook(display.mlx, &render, &display);
	mlx_hook(display.window, EVENT_CLOSE, 0, close_window, &display);
	mlx_key_hook(display.window, key_press, &display);
	mlx_loop(display.mlx);
	return (0);
}
