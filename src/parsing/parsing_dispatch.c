/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:30:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/17 14:15:57 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"
#include "parsing.h"
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

int	parse_bonus_objects(char *identifier, char **line_splited,
		t_display *display)
{
	if (ft_strncmp(identifier, "sp", 2) == 0)
		return (bonus_check(line_splited, display));
	else if (ft_strncmp(identifier, "pl", 2) == 0)
		return (bonus_check(line_splited, display));
	else if (ft_strncmp(identifier, "cy", 2) == 0)
		return (bonus_check(line_splited, display));
	return (0);
}
