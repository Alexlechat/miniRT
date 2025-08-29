/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:34:25 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/29 09:30:49 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

static int	validate_color_values(char **arg_splited, int word_count)
{
	int	i;
	int	val;
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
		{
			val = ft_atoi(arg_splited[i]);
			if (val < 0 || val > 255)
				result = 0;
			else
				i++;
		}
	}
	return (result);
}

int	color_check(char *str)
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
	result = validate_color_values(arg_splited, 3);
	free_str(arg_splited);
	return (result);
}
