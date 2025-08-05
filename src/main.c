/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anto <anto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:26:00 by allefran          #+#    #+#             */
/*   Updated: 2025/08/05 20:35:25 by anto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./miniRT <scene.rt>\n", 2);
		return (1);
	}
	if (!parse_rt_file(argv[1], &scene))
	{
		if (validate_rt_extension(argv[1]))
			ft_putstr_fd("Failed to parse scene file\n", 2);
		free_scene(&scene);
		return (1);
	}
	free_scene(&scene);
	ft_putstr_fd("\nParsing OK\n", 1);
	return (0);
}
