/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:22 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 08:47:13 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	light(char **line)
{
	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2] && !fov_check(line[2]))
		return (0);
	if (line[3] && !color_check(line[3]))
		return (0);
	if (line[4])
		return (0);
	return (1);
}
