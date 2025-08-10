/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:22 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 17:29:34 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	light(char **line, int *light_count)
{
	if (!line || !light_count)
		return (0);
	if (!line[0] || !line[1] || !line[2] || !line[3])
		return (0);
	if (line[4] != NULL)
		return (0);
	if (!coordinate_check(line[1]))
		return (0);
	if (!ratio_check(line[2]))
		return (0);
	if (!color_check(line[3]))
		return (0);
	(*light_count)++;
	if (*light_count > 1)
		return (0);
	return (1);
}
