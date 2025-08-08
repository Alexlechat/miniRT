/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:32 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 08:42:08 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	camera(char **line)
{
	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2] && !vector_orientation_check(line[2]))
		return (0);
	if (line[3] && !fov_check(line[3]))
		return (0);
	if (line[4])
		return (0);
	return (1);
}
