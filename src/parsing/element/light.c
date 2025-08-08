/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:22 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 14:33:48 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	light(char **line, int *l_count)
{
	if (line[1] && !coordinate_check(line[1]))
		return (0);
	if (line[2] && !ratio_check(line[2]))
		return (0);
	if (line[3] && !color_check(line[3]))
		return (0);
	if (line[4])
		return (0);
	l_count[1] += 1;
	if (l_count[1] > 1)
		return (0);
	return (1);
}
