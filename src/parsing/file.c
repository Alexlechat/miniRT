/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:34:33 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 14:10:38 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <fcntl.h>
#include <unistd.h>

static int	file_exist(char *file_name);
static int	validate_file_name(char *file_name);

int	validate_file(char *file_name)
{
	if (!file_exist(file_name))
		return (0);
	if (!validate_file_name(file_name))
		return (0);
	return (1);
}

static int	validate_file_name(char *file_name)
{
	int	i;

	i = ft_strlen(file_name) - 3;
	if (ft_strncmp(file_name + i, ".rt", 3) != 0)
		return (0);
	return (1);
}

static int	file_exist(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
