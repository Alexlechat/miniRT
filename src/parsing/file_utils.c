/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:01:01 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/05 20:57:25 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//Valide l'extension du fichier .rt
int	validate_rt_extension(const char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 3)
		return (0);
	if (ft_strncmp(filename + len - 3, ".rt", 3) != 0)
		return (0);
	return (1);
}

//Initialise une scène avec des valeurs par défaut
void	init_scene(t_scene *scene)
{
	ft_memset(scene, 0, sizeof(t_scene));
	scene->spheres = NULL;
	scene->planes = NULL;
	scene->cylinders = NULL;
	scene->num_spheres = 0;
	scene->num_planes = 0;
	scene->num_cylinders = 0;
}

// Affiche le résultat du parsing
void	print_parse_result(int line_count)
{
	if (line_count == 0)
		ft_putstr_fd("Error: No valid lines found in file\n", 2);
	else
	{
		ft_putstr_fd("File parsed successfully: ", 1);
		ft_putnbr_fd(line_count, 1);
		ft_putstr_fd(" lines processed\n", 1);
	}
}
