/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:14 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 13:49:59 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ambient(char **line, int *a_count)
{
	if (line[1] && !ratio_check(line[1]))
		return (0);
	if (line[2] && !color_check(line[2]))
		return (0);
	if (line[3])
		return (0);
	a_count[0] += 1;
	if (a_count[0] > 1)
		return (0);
	return (1);
}
