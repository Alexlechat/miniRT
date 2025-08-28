/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:19:21 by allefran          #+#    #+#             */
/*   Updated: 2025/08/28 17:09:23 by anpicard         ###   ########.fr       */
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
