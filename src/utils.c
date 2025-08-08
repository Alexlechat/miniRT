/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:19:21 by allefran          #+#    #+#             */
/*   Updated: 2025/08/08 08:27:39 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

int print_error(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	return (-1);
}

char	*trim_newline(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t')
			str[i] = '\0';
		i++;
	}
	return (str);
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