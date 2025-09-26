/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:04:10 by allefran          #+#    #+#             */
/*   Updated: 2025/09/26 11:36:10 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	convert_color(t_color color)
{
	int	hex;

	hex = 0;
	hex = color.r << 16;
	hex = hex | color.g << 8;
	hex = hex | color.b;
	return (hex);
}

t_color	create_color(int r, int g, int b)
{
	t_color	new_color;

	new_color.r = r;
	new_color.g = g;
	new_color.b = b;
	return (new_color);
}
