/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:15:00 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/12 14:15:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

double	calc_ambient(double obj_c, double amb_c, double brightness)
{
	return ((obj_c / 255.0) * (amb_c / 255.0) * brightness * 255.0 * 0.3);
}

unsigned char	clamp_color(double ambient, double diffuse)
{
	if (ambient + diffuse > 255)
		return (255);
	return ((unsigned char)(ambient + diffuse));
}
