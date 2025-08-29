/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:19:21 by allefran          #+#    #+#             */
/*   Updated: 2025/08/29 11:45:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "display.h"
#include <stdlib.h>

void	free_str(char **str)
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

void	free_display(t_display *display)
{
	if (!display)
		return ;
	if (display->sphere)
	{
		free(display->sphere);
		display->sphere = NULL;
	}
	if (display->plane)
	{
		free(display->plane);
		display->plane = NULL;
	}
	if (display->cylinder)
	{
		free(display->cylinder);
		display->cylinder = NULL;
	}
}

int	print_error(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	return (0);
}

int	count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
