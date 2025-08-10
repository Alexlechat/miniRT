/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apicard <apicard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:00 by apicard           #+#    #+#             */
/*   Updated: 2025/01/08 18:08:00 by apicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../../libft/includes/libft.h"
#include <stdlib.h>

static int	validate_coordinate_values(char **arg_splited, int word_count)
{
	int	i;
	int	result;

	result = 1;
	i = 0;
	while (i < 3 && result)
	{
		if (!arg_splited[i] || i >= word_count)
			result = 0;
		else if (!*arg_splited[i] || !is_valid_number(arg_splited[i]))
			result = 0;
		else
			i++;
	}
	return (result);
}

int	coordinate_check(char *str)
{
	char	**arg_splited;
	int		result;

	if (!str || !*str)
		return (0);
	if (!check_consecutive_commas(str))
		return (0);
	arg_splited = split_and_validate_count(str);
	if (!arg_splited)
		return (0);
	result = validate_coordinate_values(arg_splited, 3);
	free_all(arg_splited);
	return (result);
}

static int	validate_vector_values(char **arg_splited, int word_count)
{
	int		i;
	double	val;
	int		result;

	result = 1;
	i = 0;
	while (i < 3 && result)
	{
		if (!arg_splited[i] || i >= word_count)
			result = 0;
		else if (!*arg_splited[i] || !is_valid_number(arg_splited[i]))
			result = 0;
		else
		{
			val = ft_atof(arg_splited[i]);
			if (val < -1.0 || val > 1.0)
				result = 0;
			else
				i++;
		}
	}
	return (result);
}

int	vector_orientation_check(char *str)
{
	char	**arg_splited;
	int		result;

	if (!str || !*str)
		return (0);
	if (!check_consecutive_commas(str))
		return (0);
	arg_splited = split_and_validate_count(str);
	if (!arg_splited)
		return (0);
	result = validate_vector_values(arg_splited, 3);
	free_all(arg_splited);
	return (result);
}
