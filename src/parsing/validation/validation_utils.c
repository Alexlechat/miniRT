/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apicard <apicard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:00 by apicard           #+#    #+#             */
/*   Updated: 2025/01/08 18:08:00 by apicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdlib.h>

int	fov_check(char *str)
{
	char	*trimmed;
	int		val;
	int		result;

	if (!str || !*str)
		return (0);
	trimmed = trim_newline(str);
	if (!trimmed)
		return (0);
	if (!is_valid_number(trimmed))
	{
		free(trimmed);
		return (0);
	}
	val = ft_atoi(trimmed);
	if (val >= 0 && val <= 180)
		result = 1;
	else
		result = 0;
	free(trimmed);
	return (result);
}

int	ratio_check(char *str)
{
	char	*trimmed;
	double	val;
	int		result;

	if (!str || !*str)
		return (0);
	trimmed = trim_newline(str);
	if (!trimmed)
		return (0);
	if (!is_valid_number(trimmed))
	{
		free(trimmed);
		return (0);
	}
	val = ft_atof(trimmed);
	if (val >= 0.0 && val <= 1.0)
		result = 1;
	else
		result = 0;
	free(trimmed);
	return (result);
}
