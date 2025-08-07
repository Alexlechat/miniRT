/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:02:14 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/07 11:51:29 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int ambient(char **line)
{
	if(line[1] && !ratio_check(line[1]))
		return (0);
	if (line[2] && !color_check(line[2]))
		return (0);
	if (line[3])
		return (0);
	return (1);
}