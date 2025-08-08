/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:19:21 by allefran          #+#    #+#             */
/*   Updated: 2025/08/08 13:14:09 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include <stdlib.h>

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*trim_newline(char *str)
{
	int		i;
	char	*str_trimed;

	i = 0;
	str_trimed = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!str_trimed)
		return (NULL);
	while (str[i])
	{
		str_trimed[i] = str[i];
		if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t')
			str_trimed[i] = '\0';
		i++;
	}
	return (str_trimed);
}

int	print_error(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	return (-1);
}

int	is_number(char **line)
{
	int	i;
	int	j;

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

int	count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
