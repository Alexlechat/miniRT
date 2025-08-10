/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:14 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 17:29:45 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ambient(char **line, int *ambient_count)
{
	if (!line || !ambient_count)
		return (0);
	if (!line[0] || !line[1] || !line[2])
		return (0);
	if (line[3] != NULL)
		return (0);
	if (!ratio_check(line[1]))
		return (0);
	if (!color_check(line[2]))
		return (0);
	(*ambient_count)++;
	if (*ambient_count > 1)
		return (0);
	return (1);
}
