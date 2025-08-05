/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:12:18 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/05 21:28:35 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//Parse un vecteur 3D au format "x,y,z"
int	parse_vec3(char *str, t_vec3 *vec)
{
	char	**split;

	if (!str || !vec)
		return (0);
	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		free_split_array(split);
		return (0);
	}
	vec->x = ft_atof(split[0]);
	vec->y = ft_atof(split[1]);
	vec->z = ft_atof(split[2]);
	free_split_array(split);
	return (1);
}

// Parse une couleur au format "r,g,b"
int	parse_color(char *str, t_color *color)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	if (!str || !color)
		return (0);
	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (free_split_array(split), 0);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (!validate_rgb_values(r, g, b))
		return (free_split_array(split), 0);
	color->r = r;
	color->g = g;
	color->b = b;
	free_split_array(split);
	return (1);
}

// Affiche les tokens d'une ligne
static void	print_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		ft_putstr_fd("[", 1);
		ft_putstr_fd(tokens[i], 1);
		ft_putstr_fd("] ", 1);
		i++;
	}
	ft_putstr_fd("\n\n", 1);
}

//Parse une ligne principale - structure de base seulement
int	parse_line(char *line, t_scene *scene)
{
	char	*trimmed;
	char	**tokens;

	if (!line || !scene)
		return (0);
	trimmed = ft_strtrim(line, " \t\n\r");
	if (!trimmed || trimmed[0] == '\0')
	{
		if (trimmed)
			free(trimmed);
		return (1);
	}
	tokens = smart_split(trimmed);
	if (!tokens)
	{
		free(trimmed);
		return (0);
	}
	if (tokens[0])
	{
		if (ft_strcmp(tokens[0], "A") == 0)
		{
			// Ambient
		}
		else if (ft_strcmp(tokens[0], "C") == 0)
		{
			// Camera
		}
		else if (ft_strcmp(tokens[0], "L") == 0)
		{
			//Light
		}
		else if (ft_strcmp(tokens[0], "s") == 0)
		{
			//Sphere
		}
		else if (ft_strcmp(tokens[0], "c") == 0)
		{
			//Cylinder
		}
		else if (ft_strcmp(tokens[0], "p") == 0)
		{
			//Plane
		}
	}
	ft_putstr_fd("Line: ", 1);
	ft_putstr_fd(trimmed, 1);
	ft_putstr_fd("\nTokens: ", 1);
	print_tokens(tokens);
	free_tokens(tokens);
	free(trimmed);
	return (1);
}
