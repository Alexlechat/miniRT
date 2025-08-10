/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:32 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 17:29:31 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	camera(char **line, int *camera_count)
{
	if (!line || !camera_count)
		return (0);
	if (!line[0] || !line[1] || !line[2] || !line[3])
		return (0);
	if (line[4] != NULL)
		return (0);
	if (!coordinate_check(line[1]))
		return (0);
	if (!vector_orientation_check(line[2]))
		return (0);
	if (!fov_check(line[3]))
		return (0);
	(*camera_count)++;
	if (*camera_count > 1)
		return (0);
	return (1);
}
