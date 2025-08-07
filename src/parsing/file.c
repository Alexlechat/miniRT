/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:34:33 by allefran          #+#    #+#             */
/*   Updated: 2025/08/07 15:35:58 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "miniRT.h"
#include "libft.h"

int	validate_file_name(char *file_name)
{
	int	i;

	i = ft_strlen(file_name) - 3;
	if(ft_strncmp(file_name + i, ".rt", 3) != 0)
		return (0);
	
	return (1);
}

int	file_exist(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return(print_error("Error\n", 2));
	}
	return (1);
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

