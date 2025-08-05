/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:30:22 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/05 20:57:50 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

// Parse la partie entière d'un nombre
static double	parse_integer_part(const char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

// Parse la partie décimale d'un nombre
static double	parse_decimal_part(const char *str, int *i)
{
	double	result;
	double	fraction;

	result = 0.0;
	fraction = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			result += (str[*i] - '0') * fraction;
			fraction *= 0.1;
			(*i)++;
		}
	}
	return (result);
}

//Fonction atof simple pour convertir string vers double
double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;

	if (!str)
		return (0.0);
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = parse_integer_part(str, &i);
	result += parse_decimal_part(str, &i);
	return (result * sign);
}

//Libère la mémoire allouée pour une scène
void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->spheres)
	{
		free(scene->spheres);
		scene->spheres = NULL;
	}
	if (scene->planes)
	{
		free(scene->planes);
		scene->planes = NULL;
	}
	if (scene->cylinders)
	{
		free(scene->cylinders);
		scene->cylinders = NULL;
	}
	scene->num_spheres = 0;
	scene->num_planes = 0;
	scene->num_cylinders = 0;
}

//Affiche un message d'erreur et quitte le programme
void	error_exit(const char *message)
{
	if (message)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd((char *)message, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(1);
}
