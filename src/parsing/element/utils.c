/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:34:25 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 09:11:57 by allefran         ###   ########.fr       */
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

int	vector_orientation_check(char *str)
{
	(void)str;
	return (1);
}

int fov_check(char *str)
{
	if (ft_atoi(trim_newline(str)) < 0 || ft_atoi(trim_newline(str)) > 180)
		return (0);
	return (1);
}
