/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_helpers.c                               :+:      :+:    :+:   */
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

int	check_consecutive_commas(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (0);
		i++;
	}
	return (1);
}

char	**split_and_validate_count(char *str)
{
	char	**arg_splited;
	int		word_count;

	arg_splited = ft_split(str, ',');
	if (!arg_splited)
		return (NULL);
	word_count = 0;
	while (arg_splited[word_count])
		word_count++;
	if (word_count != 3)
	{
		free_str(arg_splited);
		return (NULL);
	}
	return (arg_splited);
}
