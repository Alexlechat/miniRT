/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:34:25 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/07 15:35:32 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include <float.h>

int	ratio_check(char *str)
{
	if (ft_atof(str) < 0 || ft_atof(str) > 1)
		return (0);
	return (1);
}

int	color_check(char *str)
{
	char	**arg_splited;
	int		i;
	int		val;

	i = 0;
	arg_splited = ft_split(str, ',');
	if (!arg_splited)
		return (-1);
	while (i < 3)
	{
		if (!arg_splited[i])
			return (0);
		val = ft_atoi(trim_newline(arg_splited[i]));
		if (val < 0 || val > 255)
			return (0);
		i++;
	}
	if (arg_splited[i])
		return (0);
	return (1);
}

int	coordinate_check(char *str)
{
	char	**arg_splited;
	int		i;

	i = 0;
	arg_splited = ft_split(str, ',');
	if (!arg_splited)
		return (-1);
	while (i < 3)
	{
		if (arg_splited[i] && (ft_atof(arg_splited[i]) < -DBL_MAX
				|| ft_atof(arg_splited[i]) > DBL_MAX))
			return (0);
		i++;
	}
	if (arg_splited[i + 1])
		return (0);
	return (1);
}

int	is_number(char **line)
{
	int i;
	int j;

	i = 1;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] != '-' && line[i][j] != '.' && line[i][j] != ','
				&& (line[i][j] < '0' || line[i][j] > '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}