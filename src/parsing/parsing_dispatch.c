/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:30:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/29 12:43:43 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "display.h"
#include "libft.h"
#include <stdlib.h>

int	parse_mandatory_elements(char *identifier, char **line_splited,
		int **counts, t_display *display)
{
	if (ft_strncmp(identifier, "A", 1) == 0)
		return (ambient(line_splited, counts[0], display));
	else if (ft_strncmp(identifier, "C", 1) == 0)
		return (camera(line_splited, counts[2], display));
	else if (ft_strncmp(identifier, "L", 1) == 0)
		return (light(line_splited, counts[1], display));
	return (-1);
}

int	parse_bonus_objects(char *identifier, char **line_splited)
{
	if (ft_strncmp(identifier, "sp", 2) == 0)
		return (bonus_check(line_splited));
	else if (ft_strncmp(identifier, "pl", 2) == 0)
		return (bonus_check(line_splited));
	else if (ft_strncmp(identifier, "cy", 2) == 0)
		return (bonus_check(line_splited));
	return (0);
}
